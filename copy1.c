struct node * copy(node *h){
    node *nhead = NULL;
    node *temp,*newnode,*ptemp,*new;
    temp = h;
    while(temp!=NULL){
        newnode = (node *)malloc(sizeof(node));
        newnode->next = temp ->next;
        temp->next = newnode;
        newnode->data = temp->data;
        temp = temp->next->next;
    }
    ptemp = h->next;
    temp = h;
    while(temp!=NULL){
        ptemp->random = temp->random->next;
        ptemp=ptemp->next->next;
        temp= temp->next->next;
    }
    temp = h;
    while(temp!=NULL){
       if(nhead==NULL)
         new = nhead = temp->next;
        else
        {
            new->next= temp->next;
            new = new->next;
        }
        temp->next=temp->next->next;
        temp = temp->next;
    }
    return nhead;
}