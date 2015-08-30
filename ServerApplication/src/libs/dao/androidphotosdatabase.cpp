#include "androidphotosdatabase.hpp"
namespace server {
using namespace litesql;
const litesql::FieldType Photo::Own::Id("id_",A_field_type_integer,"Photo_");
const std::string Photo::type__("Photo");
const std::string Photo::table__("Photo_");
const std::string Photo::sequence__("Photo_seq");
const litesql::FieldType Photo::Id("id_",A_field_type_integer,table__);
const litesql::FieldType Photo::Type("type_",A_field_type_string,table__);
const litesql::FieldType Photo::Data("data_",A_field_type_blob,table__);
const litesql::FieldType Photo::Datasize("datasize_",A_field_type_integer,table__);
const litesql::FieldType Photo::Checksum("checksum_",A_field_type_integer,table__);
void Photo::initValues() {
}
void Photo::defaults() {
    id = 0;
    data = Blob();
    datasize = 0;
    checksum = 0;
}
Photo::Photo(const litesql::Database& db)
     : litesql::Persistent(db), id(Id), type(Type), data(Data), datasize(Datasize), checksum(Checksum) {
    defaults();
}
Photo::Photo(const litesql::Database& db, const litesql::Record& rec)
     : litesql::Persistent(db, rec), id(Id), type(Type), data(Data), datasize(Datasize), checksum(Checksum) {
    defaults();
    size_t size = (rec.size() > 5) ? 5 : rec.size();
    switch(size) {
    case 5: checksum = convert<const std::string&, int>(rec[4]);
        checksum.setModified(false);
    case 4: datasize = convert<const std::string&, int>(rec[3]);
        datasize.setModified(false);
    case 3: data = convert<const std::string&, litesql::Blob>(rec[2]);
        data.setModified(false);
    case 2: type = convert<const std::string&, std::string>(rec[1]);
        type.setModified(false);
    case 1: id = convert<const std::string&, int>(rec[0]);
        id.setModified(false);
    }
}
Photo::Photo(const Photo& obj)
     : litesql::Persistent(obj), id(obj.id), type(obj.type), data(obj.data), datasize(obj.datasize), checksum(obj.checksum) {
}
const Photo& Photo::operator=(const Photo& obj) {
    if (this != &obj) {
        id = obj.id;
        type = obj.type;
        data = obj.data;
        datasize = obj.datasize;
        checksum = obj.checksum;
    }
    litesql::Persistent::operator=(obj);
    return *this;
}
std::string Photo::insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs) {
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
    fields.push_back(datasize.name());
    values.push_back(datasize);
    datasize.setModified(false);
    fields.push_back(checksum.name());
    values.push_back(checksum);
    checksum.setModified(false);
    fieldRecs.push_back(fields);
    valueRecs.push_back(values);
    return litesql::Persistent::insert(tables, fieldRecs, valueRecs, sequence__);
}
void Photo::create() {
    litesql::Record tables;
    litesql::Records fieldRecs;
    litesql::Records valueRecs;
    type = type__;
    std::string newID = insert(tables, fieldRecs, valueRecs);
    if (id == 0)
        id = newID;
}
void Photo::addUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    updateField(updates, table__, id);
    updateField(updates, table__, type);
    updateField(updates, table__, data);
    updateField(updates, table__, datasize);
    updateField(updates, table__, checksum);
}
void Photo::addIDUpdates(Updates& updates) {
}
void Photo::getFieldTypes(std::vector<litesql::FieldType>& ftypes) {
    ftypes.push_back(Id);
    ftypes.push_back(Type);
    ftypes.push_back(Data);
    ftypes.push_back(Datasize);
    ftypes.push_back(Checksum);
}
void Photo::delRecord() {
    deleteFromTable(table__, id);
}
void Photo::delRelations() {
}
void Photo::update() {
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
void Photo::del() {
    if (!typeIsCorrect()) {
        std::auto_ptr<Photo> p(upcastCopy());
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
bool Photo::typeIsCorrect() const {
    return type == type__;
}
std::auto_ptr<Photo> Photo::upcast() const {
    return auto_ptr<Photo>(new Photo(*this));
}
std::auto_ptr<Photo> Photo::upcastCopy() const {
    Photo* np = new Photo(*this);
    np->id = id;
    np->type = type;
    np->data = data;
    np->datasize = datasize;
    np->checksum = checksum;
    np->inDatabase = inDatabase;
    return auto_ptr<Photo>(np);
}
std::ostream & operator<<(std::ostream& os, Photo o) {
    os << "-------------------------------------" << std::endl;
    os << o.id.name() << " = " << o.id << std::endl;
    os << o.type.name() << " = " << o.type << std::endl;
    os << o.data.name() << " = " << o.data << std::endl;
    os << o.datasize.name() << " = " << o.datasize << std::endl;
    os << o.checksum.name() << " = " << o.checksum << std::endl;
    os << "-------------------------------------" << std::endl;
    return os;
}
AndroidPhotosDatabase::AndroidPhotosDatabase(std::string backendType, std::string connInfo)
     : litesql::Database(backendType, connInfo) {
    initialize();
}
std::vector<litesql::Database::SchemaItem> AndroidPhotosDatabase::getSchema() const {
    vector<Database::SchemaItem> res;
    string TEXT = backend->getSQLType(A_field_type_string);
    string rowIdType = backend->getRowIDType();
    res.push_back(Database::SchemaItem("schema_","table","CREATE TABLE schema_ (name_ "+TEXT+", type_ "+TEXT+", sql_ "+TEXT+")"));
    if (backend->supportsSequences()) {
        res.push_back(Database::SchemaItem("Photo_seq","sequence",backend->getCreateSequenceSQL("Photo_seq")));
    }
    res.push_back(Database::SchemaItem("Photo_","table","CREATE TABLE Photo_ (id_ " + rowIdType + ",type_ " + backend->getSQLType(A_field_type_string,"") + "" +",data_ " + backend->getSQLType(A_field_type_blob,"") + "" +",datasize_ " + backend->getSQLType(A_field_type_integer,"") + "" +",checksum_ " + backend->getSQLType(A_field_type_integer,"") + "" +")"));
    res.push_back(Database::SchemaItem("Photo_id_idx","index","CREATE INDEX Photo_id_idx ON Photo_ (id_)"));
    return res;
}
void AndroidPhotosDatabase::initialize() {
    static bool initialized = false;
    if (initialized)
        return;
    initialized = true;
}
}
