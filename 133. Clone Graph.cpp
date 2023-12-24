#include <vector>
#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return node;
        }
        Node *clone = new Node(node->val);
        if(node->neighbors.size() == 0){
            return clone;
        }
        dict[node] = clone;

        vector<Node*> nodeVec;
        for(auto nextNode:node->neighbors){
            if(dict.count(nextNode)){
                nodeVec.push_back(dict[nextNode]);
            }else{
                auto cloneNode = cloneGraph(nextNode);
                nodeVec.push_back(cloneNode);
            }
        }
        clone->neighbors = nodeVec;

        return clone;
    }
private:
    unordered_map<Node*, Node*> dict;//<old Node, new Node>
};