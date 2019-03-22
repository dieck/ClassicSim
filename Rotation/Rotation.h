#ifndef ROTATION_H
#define ROTATION_H

#include <QMap>
#include <QVector>

#include "Resource.h"

class Buff;
class Character;
class RotationExecutor;
class Spell;

class Rotation {
public:
    Rotation(QString class_name);
    virtual ~Rotation();

    void perform_rotation() const;

    void set_name(const QString& name);
    void set_description(const QString& desc);
    void add_variable(const QString& var, const QString& value);
    void add_prerequisite(const QString& key, const QString& value);
    void add_executor(RotationExecutor* executor);

    QString get_class() const;
    QString get_name() const;
    QString get_description() const;

    void link_spells(Character *pchar);
    bool add_conditionals(RotationExecutor*);

    void dump();

private:
    Character* pchar;
    QString class_name;
    QString name;
    QString description;
    QMap<QString, QString> defined_variables;
    QMap<QString, QString> prerequisites;
    QVector<RotationExecutor*> rotation_executors;

    ResourceType get_resource_from_string(const QString& resource) const;
};

#endif // ROTATION_H
