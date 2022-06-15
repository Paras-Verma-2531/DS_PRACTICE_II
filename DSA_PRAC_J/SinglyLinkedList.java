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

    }
    public int deleteFromEnd()
    {

    }
    public int deleteFromPos(int pos)
    {

    }
}
