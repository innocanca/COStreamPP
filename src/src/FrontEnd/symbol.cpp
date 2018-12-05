#include "symbol.h"
int Level;
int current_version[MAX_SCOPE_DEPTH];
/* enterScope */
void EnterScope()
{
    Level++;
    if (Level == MAX_SCOPE_DEPTH) {
	    cout<<"Internal Error: out of nesting levels!\n";
	    exit(-1);
    }
    current_version[Level]++;
}

void ExitScope()
{
    if (Level == 0) {
		cout<<"missing '{' detected"<<endl;
    } 
	Level--;
}

void SymbolTable::InsertSymbol(identifierNode* node){
    if(iTable.find(node->name)==iTable.end()){
        iTable[node->name].push_back(node);
    }else{
        /* 暂时保留 可能需要添加内容 */
         iTable[node->name].push_back(node);
    }
    return ;
}

/* 必须查找上层作用域名 还未修改*/
bool SymbolTable::LookupSymbol(string  name){
    auto iter=iTable.find(name);
    if(iter==iTable.end())
        return false;
    for(auto it=iTable[name].begin();it!=iTable[name].end();it++){
        if((*it)->level==Level && (*it)->version==current_version[Level])
            return true;
    }
    return false;
}

const identifierNode* SymbolTable::operator[](string str){
    auto iter=iTable.find(str);
    if(iter!=iTable.end()){
        for(auto it=iTable[str].begin();it!=iTable[str].end();it++){
        if((*it)->level==Level && (*it)->version==current_version[Level])
            return (*it);
    }
    }
    /*
    if(functionTable.find(str)!=functionTable.end())
        return functionTable[str];
    if(compositeTable.find(str)!=compositeTable.end())  
        return compositeTable[str];
    */
    return NULL;
}