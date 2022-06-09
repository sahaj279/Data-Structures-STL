#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
      int data;
      Node *left;
      Node *right;

      Node(int val)
      {
            data = val;
            left = NULL;
            right = NULL;
      }
};
void iterative_preorder(Node *root){
      if(root){
            stack<Node*>st;
            st.push(root);
            while(!st.empty()){
                  Node *node=st.top();
                  cout<<node->data<<" ";
                  st.pop();
                  if(node->right)st.push(node->right);
                  if(node->left)st.push(node->left);

            }
      }
}

void preorder(Node *root)
{
      if (root)
      {

            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
      }
}
void inorder(Node *root)
{
      if (root)
      {

            preorder(root->left);
            cout << root->data << " ";
            preorder(root->right);
      }
}
void postorder(Node *root)
{
      if (root)
      {

            preorder(root->left);
            preorder(root->right);
            cout << root->data << " ";
      }
}
void bfs(Node *root)
{
      queue<Node *> q;
      if (root)
      {
            q.push(root);
            while (!q.empty())
            {
                  int size = q.size();
                  for (int i = 0; i < size; i++)
                  {

                        Node *node = q.front();
                        if (node->left)
                              q.push(node->left);
                        if (node->right)
                              q.push(node->right);
                        q.pop();
                        cout << node->data << " ";
                  }
                  cout<<endl;
            }
            if (root->left)
                  q.push(root->left);
            if (root->right)
                  q.push(root->right);
      }
}
int main()
{
      class Node *root = new Node(1);
      root->left = new Node(2);
      root->right = new Node(3);
      root->right->left = new Node(4);
      preorder(root);
      cout << endl;
      postorder(root);
      cout << endl;
      inorder(root);
      cout << endl;
      bfs(root);
      iterative_preorder(root);
      // just for streak
      return 0;
}