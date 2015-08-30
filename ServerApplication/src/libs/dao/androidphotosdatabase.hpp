#ifndef androidphotosdatabase_hpp
#define androidphotosdatabase_hpp
#include "litesql.hpp"
namespace server {
class Photo;
class Photo : public litesql::Persistent {
public:
    class Own {
    public:
        static const litesql::FieldType Id;
    };
    static const std::string type__;
    static const std::string table__;
    static const std::string sequence__;
    static const litesql::FieldType Id;
    litesql::Field<int> id;
    static const litesql::FieldType Type;
    litesql::Field<std::string> type;
    static const litesql::FieldType Data;
    litesql::Field<litesql::Blob> data;
    static const litesql::FieldType Datasize;
    litesql::Field<int> datasize;
    static const litesql::FieldType Checksum;
    litesql::Field<int> checksum;
    static void initValues();
protected:
    void defaults();
public:
    Photo(const litesql::Database& db);
    Photo(const litesql::Database& db, const litesql::Record& rec);
    Photo(const Photo& obj);
    const Photo& operator=(const Photo& obj);
protected:
    std::string insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs);
    void create();
    virtual void addUpdates(Updates& updates);
    virtual void addIDUpdates(Updates& updates);
public:
    static void getFieldTypes(std::vector<litesql::FieldType>& ftypes);
protected:
    virtual void delRecord();
    virtual void delRelations();
public:
    virtual void update();
    virtual void del();
    virtual bool typeIsCorrect() const;
    std::auto_ptr<Photo> upcast() const;
    std::auto_ptr<Photo> upcastCopy() const;
};
std::ostream & operator<<(std::ostream& os, Photo o);
class AndroidPhotosDatabase : public litesql::Database {
public:
    AndroidPhotosDatabase(std::string backendType, std::string connInfo);
protected:
    virtual std::vector<litesql::Database::SchemaItem> getSchema() const;
    static void initialize();
};
}
#endif
