/****************************************************************************
** Meta object code from reading C++ file 'AppDatabase.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/database/AppDatabase.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppDatabase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN14RecipeDatabaseE_t {};
} // unnamed namespace

template <> constexpr inline auto RecipeDatabase::qt_create_metaobjectdata<qt_meta_tag_ZN14RecipeDatabaseE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "RecipeDatabase",
        "recipeLoaded",
        "",
        "QVariantMap",
        "recipe",
        "getDishes",
        "QVariantList",
        "getRecipe",
        "id",
        "addRecipe",
        "name",
        "imagePath",
        "steps"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'recipeLoaded'
        QtMocHelpers::SignalData<void(const QVariantMap &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Method 'getDishes'
        QtMocHelpers::MethodData<QVariantList()>(5, 2, QMC::AccessPublic, 0x80000000 | 6),
        // Method 'getRecipe'
        QtMocHelpers::MethodData<QVariantMap(int)>(7, 2, QMC::AccessPublic, 0x80000000 | 3, {{
            { QMetaType::Int, 8 },
        }}),
        // Method 'addRecipe'
        QtMocHelpers::MethodData<bool(const QString &, const QString &, const QString &)>(9, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 10 }, { QMetaType::QString, 11 }, { QMetaType::QString, 12 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<RecipeDatabase, qt_meta_tag_ZN14RecipeDatabaseE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject RecipeDatabase::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14RecipeDatabaseE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14RecipeDatabaseE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14RecipeDatabaseE_t>.metaTypes,
    nullptr
} };

void RecipeDatabase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<RecipeDatabase *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->recipeLoaded((*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 1: { QVariantList _r = _t->getDishes();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 2: { QVariantMap _r = _t->getRecipe((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->addRecipe((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (RecipeDatabase::*)(const QVariantMap & )>(_a, &RecipeDatabase::recipeLoaded, 0))
            return;
    }
}

const QMetaObject *RecipeDatabase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RecipeDatabase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14RecipeDatabaseE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RecipeDatabase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void RecipeDatabase::recipeLoaded(const QVariantMap & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
QT_WARNING_POP
