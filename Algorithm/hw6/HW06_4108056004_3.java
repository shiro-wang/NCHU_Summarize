public class HW06_4108056004_3 extends Dessert_Desert{
    public HW06_4108056004_3(){
    }
    
    static int[] max = new int [100000];
    static int[] min = new int [100000];
    static int m;
    static int mount;
    public int[] maxBlocks(int[][] array){
        int num = array.length;
        int[] result = new int[num];
        for(int i=0;i<num;i++){
            mount = array[i].length;
            m = 0;
            max[m] = array[i][0]; 
            min[m] = array[i][0];

            for(int j=1;j<mount;j++){
                if(array[i][j]<max[m]){
                    if(array[i][j]<min[m]){
                        min[m] = array[i][j];
                    }
                }else{
                    m++;
                    max[m] = array[i][j]; min[m] = array[i][j];
                }
            }

            for(int j=m;j>0;j--){
                if(min[j] < max[j-1] || min[j] < min[j-1]){
                    if(min[j] < min[j-1]){
                        min[j-1] = min[j];
                    }
                    m--;
                }
            }
            m++;
            result[i] = m;
        }

        return result;
    }
    
}