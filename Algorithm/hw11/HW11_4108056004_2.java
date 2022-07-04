public class HW11_4108056004_2 extends GroupCounting{
    public HW11_4108056004_2(){
    }
    
    static public int c = 20000;
    public int count(String[] A, String[] B){
        Gragh graph=new Gragh(A,B);
        int hashlong = graph.hashset.bucket.length;
        
        int islandnum = 0;
        for(int i=0;i<hashlong;i++)
        {
            if(graph.hashset.bucket[i]!=null)
            {
                Element temp=graph.hashset.bucket[i];
                while(temp!=null)
                {
                    if(temp.marked==0)
                    {
                        ChinaQueue queue = new ChinaQueue(10);
                        bfs(temp.key,graph,islandnum,queue,hashlong);
                        islandnum++;
                    }
                    temp=temp.next;
                }
            }
        }
        
        return islandnum;
    }
    
    class Gragh
    {
        public Hash hashset;

        public Gragh(String[] A, String[] B)
        {
            int n = A.length;
            hashset=new Hash();
            for(int i=0;i<n;i++)
                hashset.put(A[i],B[i]);
        }
        
    }
    class Element
    {
        public String key;
        public int marked;
        public int distto;
        public int islandnum;
        
        public ArrayList val;
        Element next;
        public Element(String key,ArrayList val)
        {
            this.key=key;
            this.val=val;
            this.marked=0;
            next=null;
        }
    }
    class Hash
    {
        public int capacity;
        Element[] bucket;

        public Hash()
        {
            this.capacity=c;
            this.bucket=new Element[capacity];
        }

        public void put(String v,String u)
        {
            append(v, u);
            append(u, v);
        }
        public void append(String v,String u)
        {
            int hash=Math.abs(v.hashCode())%capacity;
            
            for(Element e=bucket[hash];e!=null;e=e.next)
                if(v.equals(e.key))
                {
                    e.val.add(u);
                    return;
                }
            
            Element newE=new Element(v,new ArrayList(u));
            newE.next=bucket[hash];
            bucket[hash]=newE;
        }

    }
    class ArrayList{
        String[] a;
        int MAX_a_SIZE;
        int num ;
        public ArrayList(String first){
            a = new String[1];
            a[0] = first;
            MAX_a_SIZE = 1;num = 1;
        }
        public void add(String na){
            if(num < MAX_a_SIZE){
                a[num] = na;
            }else{
                a = I_NEED_MORE(a);
                a[num] = na;
            }
            num++;
        }

        public String get(int n){
            return a[n];
        }
        public int size(){
            return num;
        }

        public String[] I_NEED_MORE(String[] a){
            MAX_a_SIZE = MAX_a_SIZE*2;
            String[] bigger_a = new String[MAX_a_SIZE];
            for(int i=0;i<MAX_a_SIZE/2;i++){
                bigger_a[i] = a[i];
            }
            return bigger_a;
        }

    }
    class ChinaQueue
    {
        int head;
        int tail;
        String[] array;
        int MAX_QUEUE_SIZE;
        public ChinaQueue(int len)
        {
            array=new String[len];
            MAX_QUEUE_SIZE = len;
            head=tail=0;
        }
        public boolean isEmpty()
        {
            return tail==head;
        }
        public String dequeue()
        {
            if (head == tail){
                System.out.println("Empty");
                return "0"; 
            }
            head = (head + 1) % MAX_QUEUE_SIZE;
            return array[head];
        }
        public void enqueue(String v)
        {
            tail = (tail + 1) % MAX_QUEUE_SIZE;
            if (head == tail){
                array=IwantMore___(array);
            }
            array[tail] = v;
        }
        public String[] IwantMore___(String[] array)
        {
            MAX_QUEUE_SIZE=MAX_QUEUE_SIZE*2;
            String[] newarray = new String[MAX_QUEUE_SIZE];
            for(int i=head;i<MAX_QUEUE_SIZE/2;i++){
                newarray[i+MAX_QUEUE_SIZE/2]=array[i];
            }
            for(int i=0;i<tail;i++){
                newarray[i]=array[i];
            }
            head+=MAX_QUEUE_SIZE/2;
            return newarray;
        }

        
        
    }
    public void bfs(String v, Gragh gragh, int islandnum, ChinaQueue q, int hashlong)
    {
        q.enqueue(v);
        Element temp = gragh.hashset.bucket[Math.abs(v.hashCode())%hashlong];
        while(temp!=null){
            if(temp.key.equals(v)){
                break;
            }
            temp=temp.next;
        }
        temp.marked = 1;
        temp.islandnum = islandnum;
        while(!q.isEmpty()){
            String s = q.dequeue();
            Element temp1 = gragh.hashset.bucket[Math.abs(s.hashCode())%hashlong];
            while(temp1!=null)
            {
                if(temp1.key.equals(s))
                    break;
                else{
                    temp1=temp1.next;
                }
            }
            temp1.islandnum=islandnum;
            
            for(int i=0;i<temp1.val.size();i++)
            {
                String qv = temp1.val.get(i);
                Element temp2 = gragh.hashset.bucket[Math.abs(qv.hashCode())%hashlong];
                while(temp2!=null)
                {
                    if(temp2.key.equals(qv))
                        break;
                    temp2=temp2.next;
                }
                if(temp2.marked == 0)
                {
                    q.enqueue(qv);
                    temp2.marked = 1;
                    temp2.islandnum=islandnum;
                }
            }
        }
    }
    
    public void clear(Gragh gragh, int hashlong){
        for(int i=0;i<hashlong;i++)
        {
            if(gragh.hashset.bucket[i]!=null)
            {
                Element temp=gragh.hashset.bucket[i];
                while(temp!=null)
                {
                    temp.marked=0;
                    temp.distto=0;
                    temp=temp.next;
                }
            }
        }
    }
    
}
