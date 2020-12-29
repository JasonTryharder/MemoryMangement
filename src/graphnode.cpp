#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
    // task 0 this instance is on stack not heap
    // delete _chatBot; 
    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    // task 4 non-owning reference 
    // _parentEdges.push_back(edge);
    _parentEdges.emplace_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    // _childEdges.push_back(edge);
    // task 4 exclusive 
    _childEdges.emplace_back(std::move(edge));
}

//// STUDENT CODE
////
//task 5 adapt this to take chatbot instance
// void GraphNode::MoveChatbotHere(ChatBot *chatbot)
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
   // task 5 adapt to move chatbot instance into GraphNode::ChatBot *_chatBot;
    _chatBot = chatbot;
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    // task 5 adapt to move chatbot instance into GraphNode::ChatBot *newNode;
    newNode->MoveChatbotHere(_chatBot);
    // task 5 instance already pass to newNode
    // _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////
    // task 4 
    return _childEdges[index].get();
    // return *(_childEdges)[index].get();

    ////
    //// EOF STUDENT CODE
}