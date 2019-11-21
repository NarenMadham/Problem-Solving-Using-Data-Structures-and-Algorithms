void reverseAlternate(Node *root){
    map<int, vector<Node *> > mp;
    queue<Node *> q;
    q.push(root);
    int lc = 1;
    int cc = 0;
    int level = 0;
    while(!q.empty()){
        Node * temp = q.front();
        q.pop();
        lc -= 1;
        mp[level].push_back(temp);
        if(temp->left){
            q.push(temp->left);
            cc += 1;
        }
        if(temp->right){
            q.push(temp->right);
            cc += 1;
        }
        if(lc == 0){
            lc = cc;
            cc = 0;
            level += 1;
        }
    }
    map<int, vector<Node *> > :: iterator it;
    for(it = mp.begin(); it!= mp.end(); it++){
        if(it->first % 2 == 0){
            continue;
        }else{
            int p1 = 0;
            int p2 = it->second.size()-1;
            while(p1 < p2){
                int t = it->second[p1]->data;
                it->second[p1]->data = it->second[p2]->data;
                it->second[p2]->data = t;
                p1 += 1;
                p2 -= 1;
            }
        }
    }
}