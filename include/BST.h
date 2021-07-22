#include <iostream>
#include <stack>

//********************************************************************************************************************
//                                             Classes definitions
//********************************************************************************************************************
template <typename T>
class Node
{
  public:
  T data;
  Node<T>* pLeftNode;
  Node<T>* pRightNode;

  /*Constructors*/
  Node() : pLeftNode(nullptr) , pRightNode(nullptr) {}
  Node(T data) : data(data) , pLeftNode(nullptr) , pRightNode(nullptr) {}
  Node(T data , Node<T>* pLeftNode, Node<T>* pRightNode) : data(data) , pLeftNode(pLeftNode) , pRightNode(pRightNode) {}

  /*Destructor*/
  ~Node()
  {
     std::cout<<"X-"<<data<<" ";
  }

  void displayNode (void)
  {
  std::cout << '{' << data << '}' ;
  }

};

template <typename T>
class BST
{
   private:
   Node<T>* pRootNode;
   Node<T>* FindParent    (T data);
   void TraverseInOrder   (Node<T>* pLocalRootNode);
   void TraversePreOrder  (Node<T>* pLocalRootNode);
   void TraversePostOrder (Node<T>* pLocalRootNode);

 public:
    /*Constructors*/
    BST() : pRootNode(nullptr) {}

  enum traverseType
   {
   InOrder =1,
   PreOrder,
   PostOrder
   };

  /*Main functions that BST class support*/
  Node<T>* Find (T data);
  void Insert(T data);
  void Display (void);
  Node<T>* Minimum (void);
  Node<T>* Maximum (void);
  void Traverse (traverseType type);
  void destroy();
  void destroyRec(Node<T>* pLocalRoot);

};
//***********************************************************************************************************************


//********************************************************************************************************************
//                                             Functions definitions
//********************************************************************************************************************

template <typename T>
Node<T>* BST<T>::FindParent (T data)
{
   Node<T>* pCurrentNode = pRootNode;
   Node<T>* pParentNode  = nullptr;

    while( pCurrentNode != nullptr )
    {
        pParentNode = pCurrentNode;

        if(data > pCurrentNode->data  )
        {
           pCurrentNode = pCurrentNode->pRightNode;
        }
        else if ( data < pCurrentNode->data)
        {
          pCurrentNode = pCurrentNode->pLeftNode;
        }
    }
    return pParentNode;
}

template <typename T>
Node<T>* BST<T>::Find (T data)
 {
    Node<T>* pCurrentNode = pRootNode;

    while( pCurrentNode->data != data )
    {
       if(data > pCurrentNode->data)
       {
           pCurrentNode = pCurrentNode->pRightNode;
       }
       else if(data < pCurrentNode->data )
       {
            pCurrentNode = pCurrentNode->pLeftNode;
       }
    }
    return pCurrentNode;
 }

template <typename T>
 Node<T>* BST<T>::Minimum (void)
  {
      Node<T>*  pCurrentNode  = pRootNode;
      Node<T>*  pPreviousNode =nullptr;

      while ( pCurrentNode != nullptr)
      {
          pPreviousNode = pCurrentNode;
          pCurrentNode  = pCurrentNode->pLeftNode;
      }
      return pCurrentNode;
  }

template <typename T>
Node<T>* BST<T>::Maximum (void)
  {
      Node<T>*  pCurrentNode  = pRootNode;
      Node<T>*  pPreviousNode = nullptr;

      while ( pCurrentNode != nullptr)
      {
          pPreviousNode = pCurrentNode;
          pCurrentNode  = pCurrentNode->pRightNode;
      }
      return pCurrentNode;
  }

template <typename T>
void BST<T>::Insert(T data)
{
    Node<T>* pParentNode = nullptr;
    Node<T>* newNode     = new Node<T>(data);
   if(pRootNode == nullptr)
   {
    pRootNode = new Node<T>(data);
   }
   else
  {
    pParentNode  = FindParent(data);
   if(data > pParentNode->data)
   {
      pParentNode->pRightNode = newNode;
   }
   else if (data < pParentNode->data)
   {
       pParentNode->pLeftNode = newNode;
   }
  }
}

template <typename T>
void BST<T>::TraverseInOrder (Node<T>* pLocalRootNode)
 {
    if(pLocalRootNode != nullptr)
    {
     TraverseInOrder(pLocalRootNode->pLeftNode);
     std::cout<<pLocalRootNode->data<< " ";
     TraverseInOrder(pLocalRootNode->pRightNode);
    }
 }

template <typename T>
void BST<T>::TraversePreOrder (Node<T>* pLocalRootNode)
 {
    if(pLocalRootNode != nullptr)
    {
     std::cout<<pLocalRootNode->data<< " ";
     TraversePreOrder(pLocalRootNode->pLeftNode);
     TraversePreOrder(pLocalRootNode->pRightNode);
    }
 }

template <typename T>
 void BST<T>::TraversePostOrder (Node<T>* pLocalRootNode)
 {
    if(pLocalRootNode != nullptr)
    {
     TraversePostOrder(pLocalRootNode->pLeftNode);
     TraversePostOrder(pLocalRootNode->pRightNode);
     std::cout<<pLocalRootNode->data<< " ";
    }
 }

template <typename T>
void BST<T>::Traverse (traverseType type)
{
switch (type)
{
   case InOrder:
   TraverseInOrder(pRootNode);
   break;

   case PreOrder:
   TraversePreOrder(pRootNode);
   break;

   case PostOrder:
   TraversePostOrder(pRootNode);
   break;
 }
std::cout<<"\r\n";
}


template <typename T>
void BST<T>::destroy() //deletes all nodes
{
  destroyRec(pRootNode);
} //start at root


template <typename T>
void BST<T>::destroyRec(Node<T>* pLocalRoot) //delete nodes in
{ // this subtree
 if(pLocalRoot != NULL)
 { //uses postOrder
  destroyRec(pLocalRoot->pLeftNode); //left subtree
  destroyRec(pLocalRoot->pRightNode); //right subtree
  delete pLocalRoot; //delete this node
 }
}

template <typename T>
void BST<T>::Display (void)
{
std::stack<Node<T>*> globalStack;
globalStack.push(pRootNode);
int nBlanks = 32;
bool isRowEmpty = false;
std::cout <<
"......................................................";
std::cout<<"\r\n";
while(isRowEmpty == false)
{
std::stack< Node<T>* > localStack;
isRowEmpty = true;
for(int j=0; j<nBlanks; j++)
std::cout << ' ';
while(globalStack.empty()==false)
{
Node<T>* temp = globalStack.top();
globalStack.pop();
if(temp != NULL)
{
std::cout << temp->data;
localStack.push(temp->pLeftNode);
localStack.push(temp->pRightNode);
if(temp->pLeftNode!= NULL ||
temp->pRightNode != NULL)
isRowEmpty = false;
}
else
{
std::cout << "--";
localStack.push(NULL);
localStack.push(NULL);
}
for(int j=0; j<nBlanks*2-2; j++)
std::cout << ' ' ;
} //end while globalStack not empty
std::cout<<"\r\n";
nBlanks /= 2;
while(localStack.empty()==false)
{
globalStack.push( localStack.top() );
localStack.pop();
}
} //end while isRowEmpty is false
std::cout<<
"......................................................";
std::cout <<"\r\n";
}
//*************************************************************************************************************************************************************************************





