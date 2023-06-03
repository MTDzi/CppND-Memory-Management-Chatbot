#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

/*
GraphNodes exclusively own the outgoing GraphEdges and hold non-owning references
to incoming GraphEdges.

In files chatlogic.h / chatlogic.cpp and graphnodes.h / graphnodes.cpp all instances
 of GraphEdge are changed in a way such that each instance of GraphNode exclusively
 owns the outgoing GraphEdges and holds non-owning references to incoming GraphEdges.
 Appropriate smart pointers are used to do this. Where required, changes are made to the
 code such that data structures and function parameters reflect the changes.


Move semantics are used when transferring ownership from class ChatLogic into
instances of GraphNode.

In files chatlogic.h / chatlogic.cpp and graphnodes.h / graphnodes.cpp, move semantics
 are used when transferring ownership from class ChatLogic, where all instances of
 GraphEdge are created, into instances of GraphNode.
*/

#include <vector>
#include <string>
#include <memory>
#include "chatbot.h"


// forward declarations
class GraphEdge;

class GraphNode
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    std::vector<std::unique_ptr<GraphEdge>> _childEdges;  // edges to subsequent nodes

    // data handles (not owned)
    std::vector<GraphEdge *> _parentEdges; // edges to preceding nodes 
    ChatBot *_chatBot;

    ////
    //// EOF STUDENT CODE

    // proprietary members
    int _id;
    std::vector<std::string> _answers;

public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    GraphEdge *GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentNode(GraphEdge *edge);
    void AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge);

    //// STUDENT CODE
    ////

    void MoveChatbotHere(ChatBot *chatbot);

    ////
    //// EOF STUDENT CODE

    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */