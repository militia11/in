#include "androiddocdatabase.hpp"
namespace server {
using namespace litesql;
const litesql::FieldType Document::Own::Id("id_",A_field_type_integer,"Document_");
const std::string Document::type__("Document");
const std::string Document::table__("Document_");
const std::string Document::sequence__("Document_seq");
const litesql::FieldType Document::Id("id_",A_field_type_integer,table__);
const litesql::FieldType Document::Type("type_",A_field_type_string,table__);
const litesql::FieldType Document::Data("data_",A_field_type_blob,table__);
const litesql::FieldType Document::Checksum("checksum_",A_field_type_integer,table__);
void Document::initValues() {
}
void Document::defaults() {
    id = 0;
    data = Blob();
    checksum = 0;
}
Document::Document(const litesql::Database& db)
     : litesql::Persistent(db), id(Id), type(Type), data(Data), checksum(Checksum) {
    defaults();
}
Document::Document(const litesql::Database& db, const litesql::Record& rec)
     : litesql::Persistent(db, rec), id(Id), type(Type), data(Data), checksum(Checksum) {
    defaults();
    size_t size = (rec.size() > 4) ? 4 : rec.size();
    switch(size) {
    case 4: checksum = convert<const std::string&, int>(rec[3]);
        checksum.setModified(false);
    case 3: data = convert<const std::string&, litesql::Blob>(rec[2]);
        data.setModified(false);
    case 2: type = convert<const std::string&, std::string>(rec[1]);
        type.setModified(false);
    case 1: id = convert<const std::string&, int>(rec[0]);
        id.setModified(false);
    }
}
Document::Document(const Document& obj)
     : litesql::Persistent(obj), id(obj.id), type(obj.type), data(obj.data), checksum(obj.checksum) {
}
const Document& Document::operator=(const Document& obj) {
    if (this != &obj) {
        id = obj.id;
        type = obj.type;
        data = obj.data;
        checksum = obj.checksum;
    }
    litesql::Persistent::operator=(obj);
    return *this;
}
std::string Document::insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs) {
    tables.push_back(table__);
    litesql::Record fields;
    litesql::Record values;
    fields.push_back(id.name());
    values.push_back(id);
    id.setModified(false);
    fields.push_back(type.name());
    values.push_back(type);
    type.setModified(false);
    fields.push_back(data.name());
    values.push_back(data);
    data.setModified(false);
    fields.push_back(checksum.name());
    values.push_back(checksum);
    checksum.setModified(false);
    fieldRecs.push_back(fields);
    valueRecs.push_back(values);
    return litesql::Persistent::insert(tables, fieldRecs, valueRecs, sequence__);
}
void Document::create() {
    litesql::Record tables;
    litesql::Records fieldRecs;
    litesql::Records valueRecs;
    type = type__;
    std::string newID = insert(tables, fieldRecs, valueRecs);
    if (id == 0)
        id = newID;
}
void Document::addUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    updateField(updates, table__, id);
    updateField(updates, table__, type);
    updateField(updates, table__, data);
    updateField(updates, table__, checksum);
}
void Document::addIDUpdates(Updates& updates) {
}
void Document::getFieldTypes(std::vector<litesql::FieldType>& ftypes) {
    ftypes.push_back(Id);
    ftypes.push_back(Type);
    ftypes.push_back(Data);
    ftypes.push_back(Checksum);
}
void Document::delRecord() {
    deleteFromTable(table__, id);
}
void Document::delRelations() {
}
void Document::update() {
    if (!inDatabase) {
        create();
        return;
    }
    Updates updates;
    addUpdates(updates);
    if (id != oldKey) {
        if (!typeIsCorrect()) 
            upcastCopy()->addIDUpdates(updates);
    }
    litesql::Persistent::update(updates);
    oldKey = id;
}
void Document::del() {
    if (!typeIsCorrect()) {
        std::auto_ptr<Document> p(upcastCopy());
        p->delRelations();
        p->onDelete();
        p->delRecord();
    } else {
        delRelations();
        onDelete();
        delRecord();
    }
    inDatabase = false;
}
bool Document::typeIsCorrect() const {
    return type == type__;
}
std::auto_ptr<Document> Document::upcast() const {
    return auto_ptr<Document>(new Document(*this));
}
std::auto_ptr<Document> Document::upcastCopy() const {
    Document* np = new Document(*this);
    np->id = id;
    np->type = type;
    np->data = data;
    np->checksum = checksum;
    np->inDatabase = inDatabase;
    return auto_ptr<Document>(np);
}
std::ostream & operator<<(std::ostream& os, Document o) {
    os << "-------------------------------------" << std::endl;
    os << o.id.name() << " = " << o.id << std::endl;
    os << o.type.name() << " = " << o.type << std::endl;
    os << o.data.name() << " = " << o.data << std::endl;
    os << o.checksum.name() << " = " << o.checksum << std::endl;
    os << "-------------------------------------" << std::endl;
    return os;
}
AndroidDocDatabase::AndroidDocDatabase(std::string backendType, std::string connInfo)
     : litesql::Database(backendType, connInfo) {
    initialize();
}
std::vector<litesql::Database::SchemaItem> AndroidDocDatabase::getSchema() const {
    vector<Database::SchemaItem> res;
    string TEXT = backend->getSQLType(A_field_type_string);
    string rowIdType = backend->getRowIDType();
    res.push_back(Database::SchemaItem("schema_","table","CREATE TABLE schema_ (name_ "+TEXT+", type_ "+TEXT+", sql_ "+TEXT+")"));
    if (backend->supportsSequences()) {
        res.push_back(Database::SchemaItem("Document_seq","sequence",backend->getCreateSequenceSQL("Document_seq")));
    }
    res.push_back(Database::SchemaItem("Document_","table","CREATE TABLE Document_ (id_ " + rowIdType + ",type_ " + backend->getSQLType(A_field_type_string,"") + "" +",data_ " + backend->getSQLType(A_field_type_blob,"") + "" +",checksum_ " + backend->getSQLType(A_field_type_integer,"") + "" +")"));
    res.push_back(Database::SchemaItem("Document_id_idx","index","CREATE INDEX Document_id_idx ON Document_ (id_)"));
    return res;
}
void AndroidDocDatabase::initialize() {
    static bool initialized = false;
    if (initialized)
        return;
    initialized = true;
}
}
