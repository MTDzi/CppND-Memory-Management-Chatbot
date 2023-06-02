#ifndef CHATBOT_H_
#define CHATBOT_H_

/*
Class design meets the Rule of Five guidelines.

In file chatbot.h / chatbot.cpp, changes are made to the class ChatBot such
 that it complies with the Rule of Five. Memory resources are properly
 allocated / deallocated on the heap and member data is copied where it makes sense.
 In each of the methods (e.g. the copy constructor), a string of the type
 "ChatBot Copy Constructor" is printed to the console so that it is possible to see
 which method is called in later examples.
*/

#include <wx/bitmap.h>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image  TODO

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////
    ChatBot(const ChatBot& other);
    ChatBot(ChatBot&& other);

    ChatBot& operator=(const ChatBot &other);
    ChatBot& operator=(ChatBot &&other);
    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    ChatLogic* GetChatLogicHandle() { return _chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
