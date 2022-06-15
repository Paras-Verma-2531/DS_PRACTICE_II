package DSA_PRAC_J;
public class Node {
    protected int data;
    protected Node next;
    protected static int length=0;
    Node(int data)
    {
        this.data=data;
        this.next=null;
        length++;
    }
}
