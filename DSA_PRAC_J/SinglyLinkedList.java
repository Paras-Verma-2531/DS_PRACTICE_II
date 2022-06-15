package DSA_PRAC_J;
public class SinglyLinkedList {
    protected Node head=null;protected Node temp;

    public void addAtBeg(int data)
    {
        Node node= new Node(data);
        if (head != null) {
            node.next = head;
        }
        head=node;
    }
    public void addAtEnd(int data)
    {
        Node node= new Node(data);
               if(head!=null)
               {
                   temp=head;
                   while(temp.next!=null)
                          temp=temp.next;
                   temp.next=node;
               }else
                   head=node;
    }
    public void addAtPos(int pos,int data)
    {
        if(pos>Node.length||pos<1)
            System.out.println("invalid position");
        if(pos==1)
            addAtBeg(data);
        else
        {
            int i=1;temp=head;
            while(i<pos-1)
            {
                temp=temp.next;i++;
            }
            Node node= new Node(data);
            node.next=temp.next;
            temp.next=node;
        }
    }
    public int deleteFromBeg()
    {
         int data=-1;
         if(head!=null)
         {Node.length--;
             data=head.data;
             head=head.next;
         }return data;
    }
    public int deleteFromEnd()
    {
         int data=-1;
         temp=head;
         if(head!=null) {
             Node.length--;
             while (temp.next.next != null)
                 temp = temp.next;
             data = temp.next.data;
             temp.next = null;
         }return data;
    }
    public int deleteFromPos(int pos)
    { int data=-1;
          if(pos>Node.length||pos<1)
              System.out.println("invalid position");
          if(pos==1)
              data=deleteFromBeg();
          if(pos==Node.length)
              data=deleteFromEnd();
          else
          {Node.length--;
              int i=1;
              temp=head;
              while(i<pos-1)
                  temp=temp.next;
              data=temp.next.data;
              temp.next=temp.next.next;
          }return data;
    }
}
