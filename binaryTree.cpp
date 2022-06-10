#include <bits/stdc++.h>
using namespace std;
void print_vec(vector<int>v){
      for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
      }
      cout<<endl;
}
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
            cout<<endl;
      }
}
void iterative_inorder(Node *root){
      if(root){
            stack<Node*>st;
                  Node *node=root;
            // st.push(root);
            while(true){
                  if(node){
                        st.push(node);
                        node=node->left;
                  }
                  else{
                        if(st.empty())break;
                        cout<<st.top()->data<<" ";
                        node=st.top()->right;
                        st.pop();
                  }
                  

            }
                  cout<<"\n";
      }
}
void iterative_postorder(Node *root){
      if(root){
            stack<Node*>st1,st2;
            st1.push(root);
            while(!st1.empty()){
                  Node *node=st1.top();
                  st1.pop();
                  st2.push(node);
                  if(node->left)st1.push(node->left);
                  if(node->right)st1.push(node->right);
            }
            while(!st2.empty()){
                  cout<<st2.top()->data<<" ";
                  st2.pop();
            }
                  cout<<"\n";
      }
}
void pre_in_post_order(Node *root){
vector<int> pre,in,post;
stack<pair<Node*,int>>st;
if(root){
      st.push({root,1});
      while(!st.empty()){
            auto  it=st.top();
            st.pop();
            if(it.second==1){
                  pre.push_back(it.first->data);
                  it.second++;
                  st.push(it);
                  if(it.first->left){
                        root=it.first->left;
                        st.push({root,1});
                  }
            }
            else if(it.second==2){
                  in.push_back(it.first->data);
                  it.second++;
                  st.push(it);
                  if(it.first->right){
                        root=it.first->right;
                        st.push({root,1});
                  }
            }
            else {
                  post.push_back(it.first->data);

            }
      }
      print_vec(pre);
      print_vec(in);
      print_vec(post);
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
void zigzag(Node * root){
      if(root){
            queue<Node *> q;
            bool flag = 0;
            q.push(root);
            while (!q.empty())
            {
                  int s = q.size();
                  if(flag==0){
                        
                  for (int i = 0; i < s; i++)
                  {
                        Node *node = q.front();
                        cout << node->data << " ";
                        if (node->left)
                              q.push(node->left);
                        if (node->right)
                              q.push(node->right);
                        q.pop();
                  }
                  cout << endl;
                  
                  }
                  else{
                        vector<int>zog;
                  for (int i = 0; i < s; i++)
                  { 
                        Node *node = q.front();
                        zog.push_back(node->data);
                        if (node->left)
                              q.push(node->left);
                        if (node->right)
                              q.push(node->right);
                        q.pop();
                  }
                  reverse(zog.begin(),zog.end());
                  print_vec(zog);
                  }
                  flag=!flag;
            }
      }
}
int maxDepth(Node *root){
      if(!root){
            return 0;
      }
      int lh=maxDepth(root->left);
      int rh=maxDepth(root->right);
      return 1+max(lh,rh);

}
int temp(Node*root){
      if(!root)return 0;
      int lh=temp(root->left);
      int rh=temp(root->right);
      if(lh==-1 || rh==-1)return -1;
      if(abs(lh-rh)>1)return -1;
      return 1+max(lh,rh);

}//temprorary function which checks if given tree is balanced or not and return -1 if not, otherwise return height of tree
bool checkBalanced(Node *root){
      if(temp(root)==-1)return false;
      return true;
}//a tree is balanced if abs(lh-rh)<=1
int diameter(Node*root,int maxi){
      if(!root)return 0;
      int lh=diameter(root->left,maxi);
      int rh=diameter(root->right,maxi);
      maxi=max(maxi,lh+rh);
      return 1+max(lh,rh);
}

int main()
{
      class Node *root = new Node(1);
      root->left = new Node(2);
      root->right = new Node(3);
      root->right->left = new Node(4);
      root->right->left->right=new Node(6);
      root->right->left->left=new Node(5);
      //   1
      //  / \
      // 2   3
      //    /
      //   4
      //  / \
      // 5   6
      preorder(root);
      cout << endl;
      postorder(root);
      cout << endl;
      inorder(root);
      cout << endl;
      bfs(root);
      iterative_preorder(root);
      iterative_inorder(root);
      iterative_postorder(root);
      pre_in_post_order(root);
      cout<<maxDepth(root);
      cout << endl;
      cout<<checkBalanced(root);
      cout << endl;
      cout<<diameter(root,0);
      cout << endl;
      zigzag(root);
      // just for streak
      return 0;
}