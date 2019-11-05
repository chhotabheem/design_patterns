#include <iostream>
using namespace std;

class Document
{
public:
    virtual Document *clone() = 0;
    virtual void print() = 0;
};

class XmlDoc : public Document
{
public:
    virtual Document *clone() override { return new XmlDoc; }
    virtual void print() override { cout << "created xml doc" << endl; }
};

class TextDoc : public Document
{
public:
    virtual Document *clone() override { return new TextDoc; }
    virtual void print() override { cout << "created text doc" << endl; }
};

enum DocType
{
    XMLDOC,
    TEXTDOC
};

class DocumentManager
{
private:
    static Document *doc[2];

public:
    static Document *create_doc(DocType type);
};

Document *DocumentManager::doc[] = {new XmlDoc, new TextDoc};

Document *DocumentManager::create_doc(DocType type)
{
    return doc[type]->clone();
}

int main()
{
    Document *xmldoc = DocumentManager::create_doc(XMLDOC);
    xmldoc->print();
    Document *textdoc = DocumentManager::create_doc(TEXTDOC);
    textdoc->print();
    return 0;
}
