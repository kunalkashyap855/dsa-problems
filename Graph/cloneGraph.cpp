/*
    Given a reference of a node in a connected undirected graph.
    Return a deep copy (clone) of the graph.
    Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

    Example 1:
      Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
      Output: [[2,4],[1,3],[2,4],[1,3]]
      Explanation: There are 4 nodes in the graph.
      1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
      2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
      3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
      4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
*/

/*
// Definition for a Node.
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
*/

Node* dfsClone(Node* node, unordered_map<Node*, Node*> &nodeMap) {
    if(nodeMap.count(node) > 0)
        return nodeMap[node];

    Node* copy = new Node(node->val);
    nodeMap[node] = copy;

    for(int i = 0; i < node->neighbors.size(); i++) {
        copy->neighbors.push_back(dfsClone(node->neighbors[i], nodeMap));
    }

    return copy;
}

Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> nodeMap;

    if(!node)
        return NULL;

    return dfsClone(node, nodeMap);
}

/*
    In this, the idea is to go through each node of the original graph (DFS) and at each node, create a copy of that node and add them to a hashmap with
    key as the original node and value as the copy node. Then for each neighbor of the original node, do the same and add the copies of the neighbors to
    the neighbors vector of the parent copy node and then return this parent copy node.
    
    Time Complexity = O(V+E)
*/
