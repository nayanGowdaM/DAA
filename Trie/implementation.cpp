#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    bool flag;

    bool hasKey( char key){
        return links[key-'a']!=NULL ;
    }

    void put( char key, Node* node){
        links[key-'a' ] = node;
    }

    Node*  get(char key){
        return links[key-'a'];
    }

    void setEnd(){
        flag=true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
        Node* root ;
    public:
        Trie(){
            root = new Node();
        }

        void insert( string& s){
            Node* node= root ;
            for( int i=0;i<s.size();i++){
                if(! node->hasKey(s[i])){
                    node->put(s[i], new Node());
                }
                node = node->get( s[i]);
            }
            node->setEnd();
        }

        bool search(string& s){
            Node* node = root ;
            for( int i=0;i<s.size();i++){
                if( !node->hasKey( s[i ])) return false;
                node= node->get(s[i]);
            }
            return node->isEnd();
        }

        bool startsWith( string& s){
            Node* node= root;
            for(int i=0;i<s.size();i++){
                if(!node->hasKey( s[i])) return false;
                node =  node->get(s[i]);
            }
            return true;
        }
};

int main()
{
	int n = 5;
	vector<int>type = {1, 1, 2, 3, 2};
	vector<string>value = {"hello", "help", "help", "hel", "hel"};
	Trie trie;
	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			trie.insert(value[i]);
		}
		else if (type[i] == 2) {
			if (trie.search(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
		else {
			if (trie.startsWith(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
	}
}