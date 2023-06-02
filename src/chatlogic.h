#ifndef CHATLOGIC_H_
#define CHATLOGIC_H_

/*
The GraphNodes in the vector _nodes are exclusively owned by the class ChatLogic.

In file chatlogic.h / chatlogic.cpp, the vector _nodes are adapted in a way that
 the instances of GraphNodes to which the vector elements refer are exclusively
 owned by the class ChatLogic. An appropriate type of smart pointer is used to achieve
 this.


GraphNode ownership is not transferred when passing instances.

When passing the GraphNode instances to functions, ownership is not transferred.


Move semantics are used correctly with ChatBot.

In file chatlogic.cpp, a local ChatBot instance is created on the stack at the bottom
 of function LoadAnswerGraphFromFile and move semantics are used to pass the ChatBot
 instance into the root node.


ChatLogic has no ownership relation to the ChatBot instance.

ChatLogic has no ownership relation to the ChatBot instance and thus is no longer
 responsible for memory allocation and deallocation.


The Chatbot prints output to indicate Rule of Five components.

When the program is executed, messages are printed to the console indicating which
 Rule of Five component of ChatBot is being called.
*/

#include <vector>
#include <string>
#include <memory>
#include "chatgui.h"

// forward declarations
class ChatBot;
class GraphEdge;
class GraphNode;

class ChatLogic
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    std::vector<std::unique_ptr<GraphNode>> _nodes;
    std::vector<std::unique_ptr<GraphEdge>> _edges;

    ////
    //// EOF STUDENT CODE

    // data handles (not owned)
    GraphNode *_currentNode;
    ChatBot *_chatBot;
    ChatBotPanelDialog *_panelDialog;

    // proprietary type definitions
    typedef std::vector<std::pair<std::string, std::string>> tokenlist;

    // proprietary functions
    template <typename T>
    void AddAllTokensToElement(std::string tokenID, tokenlist &tokens, T &element);

public:
    // constructor / destructor
    ChatLogic();
    ~ChatLogic();

    // getter / setter
    void SetPanelDialogHandle(ChatBotPanelDialog *panelDialog);
    void SetChatbotHandle(ChatBot *chatbot);

    // proprietary functions
    void LoadAnswerGraphFromFile(std::string filename);
    void SendMessageToChatbot(std::string message);
    void SendMessageToUser(std::string message);
    wxBitmap *GetImageFromChatbot();
};

#endif /* CHATLOGIC_H_ */