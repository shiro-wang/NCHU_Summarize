public class HW05_4108056004_1 extends LLK{
    public HW05_4108056004_1(){
    }
    
    
    public boolean checkLLK(int[][] array){
        int i,j,k;
        int num = array.length;
        int limit = num-2;
        double m;
        boolean tf = true;
        double[] xy;
        int m_mount;
        int count;
        quick(array);

        for(i=0;i<limit && tf;i++){
            m_mount = num-i-1;
            count = 0;
            xy = new double [m_mount];

            for(j=i+1;j<num;j++){
                if(array[i][0] == array[j][0]){
                    if(array[i][0] == array[j+1][0]){
                        tf = false;
                        break;
                    }
                }else{
                    m = ((double)array[i][1]-(double)array[j][1])/(double)(array[i][0]-(double)array[j][0]);
                    xy[count++] = m;
                } 
            } 
            count--;
            for(k=0;k<count;k++){
                if(xy[k] == xy[k+1]){
                    tf = false;
                    break;
                }
            }
        }
        
        if(tf){
            return false;
        }else{
            return true;
        }
    }
    public static void quick(int[][] number) {
        sort(number, 0, number.length-1);
    }
    
    private static void sort(int[][] number, int left, int right) {
        if(left < right) { 
            int q = partition(number, left, right); 
            sort(number, left, q-1); 
            sort(number, q+1, right); 
        } 

    }

    private static int partition(int number[][], int left, int right) {  
        int i = left - 1; 
        for(int j = left; j < right; j++) { 
            if(number[j][0] <= number[right][0]) { 
                i++; 
                swap(number, i, j); 
            } 
        } 
        swap(number, i+1, right); 
        return i+1; 
    } 

    private static void swap(int[][] number, int i, int j) {
        int t = number[i][0]; 
        int x = number[i][1];
        number[i][0] = number[j][0]; 
        number[i][1] = number[j][1];
        number[j][0] = t;
        number[j][1] = x;
    }
}