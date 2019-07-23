// import java.util.ArrayList;

public class ListMain {
    public static void main(String[] args) throws ZeroLenException, IndexOutOfBoundsException {
        List list = new List(50);
        List list2 = list;
        list.push_back(10);
        list.push_back(12);
        
        list.push_back( 6);

        System.out.println("Size:" + list.size());

        list.sort();

        System.out.println("Size:" + list.size());
        System.out.println("Find:" + list.find(11));

        System.out.println("Pop back:" + list.pop_back());
        System.out.println("List:" + list);
        // System.out.println("List2:" + list2);
        System.out.println("equals:" + list.equals(list2));
        System.out.println("get:" + list.get(0));
    }
}
//public class ArrayList implements List, Cloneable