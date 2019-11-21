/* Function to print nodes of extreme corners
of each level in alternate order */
void printExtremeNodes(Node* root){
    map<int, deque<int> > mp;
    int lc = 1;
    int cc = 0;
    int level = 0;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node * temp = q.front();
        q.pop();
        lc -= 1;
        mp[level].push_front(temp->data);
        if(temp->left != NULL){
            q.push(temp->left);
            cc += 1;
        }
        if(temp->right != NULL){
            q.push(temp->right);
            cc += 1;
        }
        if(lc == 0){
            lc = cc;
            cc = 0;
            level += 1;
        }
    }
    map<int, deque<int> > :: iterator it;
    for(it = mp.begin(); it != mp.end(); it++){
        if(it->first % 2 == 0){
            cout<<it->second.front()<<" ";
        }else{
            cout<<it->second.back()<<" ";
        }
    }
}