#include<queue>
#include<vector>
template<typename T>

class node{
	public:
		T data;
		node<T>* next;

		node(T data){
			this -> data = data;
			this -> next = NULL;
		}
};

vector<node<int>*> createLLforEachLevel(BinaryTreeNode<int>* root)
{
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    q.push(NULL);
    node<int> *head = NULL;
    node<int> *tail = NULL;
    BinaryTreeNode<int> *current = NULL;
    vector<node<int>*> output;
    
    while(true){
        if(q.front() == NULL && q.size() == 1)
        {
            output.push_back(head);
            break;
        }
        else
            {
                current = q.front();
                q.pop();
                if(current != NULL)
                    {
                        if(head == NULL)
                            {
                                head = new node<int>(current -> data);
                                tail = head;
                            }
                        else
                            {
                                tail -> next = new node<int>(current -> data); 
                                tail = tail -> next;
                            }
                    	
                    	//cout<<tail -> data<<endl;
                    
                        if(current -> left != NULL)
                            q.push(current -> left);
                        if(current -> right != NULL)
                            q.push(current -> right);
                    }
                else
                    {
                        output.push_back(head);
                        q.push(NULL);
                        head = NULL;
                        tail = NULL;
                    }
                }
            }
    
	return output;            
}



