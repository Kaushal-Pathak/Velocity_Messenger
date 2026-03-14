#include <QObject>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantList>

class VelocityManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool isConnected READ isConnected NOTIFY connectionChanged)

public:
    explicit VelocityManager(QObject *parent = nullptr) : QObject(parent) {
        m_socket = new QTcpSocket(this);
        connect(m_socket, &QTcpSocket::readyRead, this, &VelocityManager::onDataReceived);
        connect(m_socket, &QTcpSocket::connected, this, &VelocityManager::connectionChanged);
        connect(m_socket, &QTcpSocket::disconnected, this, &VelocityManager::connectionChanged);
    }

    bool isConnected() const {
        return m_socket->state() == QAbstractSocket::ConnectedState;
    }

    Q_INVOKABLE void connectToServer(const QString &host, quint16 port) {
        if (m_socket->state() != QAbstractSocket::ConnectedState) {
            m_socket->connectToHost(host, port);
        }
    }

    Q_INVOKABLE void sendMessage(const QString &user, const QString &content) {
        if (isConnected()) {
            QJsonObject message;
            message["sender"] = user;
            message["content"] = content;
            message["timestamp"] = QDateTime::currentDateTime().toString(Qt::ISODate);
            m_socket->write(QJsonDocument(message).toJson(QJsonDocument::Compact));
        }
    }

signals:
    void connectionChanged();
    void newMessageReceived(QVariantMap messageData);

private slots:
    void onDataReceived() {
        QByteArray data = m_socket->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (!doc.isNull() && doc.isObject()) {
            emit newMessageReceived(doc.object().toVariantMap());
        }
    }

private:
    QTcpSocket *m_socket;
};

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "velocitymanager.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    VelocityManager* manager = new VelocityManager(&app);
    engine.rootContext()->setContextProperty("VelocityManager", manager);

    const QUrl url(u"qrc:/Velocity/main.qml"_qs);
    engine.load(url);

    return app.exec();
}
