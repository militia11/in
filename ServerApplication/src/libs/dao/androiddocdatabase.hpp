#ifndef androiddocdatabase_hpp
#define androiddocdatabase_hpp
#include "litesql.hpp"
namespace server {
class Document;
class Document : public litesql::Persistent {
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
    litesql::Field<int> data;
    static const litesql::FieldType Checksum;
    litesql::Field<int> checksum;
    static void initValues();
protected:
    void defaults();
public:
    Document(const litesql::Database& db);
    Document(const litesql::Database& db, const litesql::Record& rec);
    Document(const Document& obj);
    const Document& operator=(const Document& obj);
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
    std::auto_ptr<Document> upcast() const;
    std::auto_ptr<Document> upcastCopy() const;
};
std::ostream & operator<<(std::ostream& os, Document o);
class AndroidDocDatabase : public litesql::Database {
public:
    AndroidDocDatabase(std::string backendType, std::string connInfo);
protected:
    virtual std::vector<litesql::Database::SchemaItem> getSchema() const;
    static void initialize();
};
}
#endif
