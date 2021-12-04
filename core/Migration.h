#ifndef MIGRATION_H
#define MIGRATION_H

class QString;

class Migration {
public:
    Migration() {}

    bool run();

private:
    bool migrate(int toVersion);
    int getVersion();
    bool setVersion(int version);

    bool runSqlFile(QString filename);

    int tableRows(QString name);

    bool updateBands();
    bool updateModes();
    bool updateExternalResource();

    static const int latestVersion = 3;
};

#endif // MIGRATION_H
