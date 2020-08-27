import java.io.File;

/**
 * @desc ɾ��ĳһ���ļ�������������ļ���
 * 
 * �߼��ǣ���ɾ�����е��ļ���ɾ�������еĵ�ǰĿ¼���ļ�֮��
 * �ٽ���ǰ�ļ���ɾ����
 */
class RemoveDir {
    
    public static void main(String[] args){
        File dir = new File("./TestFolder");

        if(dir.exists()){

            removeDir(dir);
        }else{
            System.out.println("TestFolder�����ڣ����ȴ���һ���ٲ���");
        }
    }

    public static void removeDir(File dir){
        // ��ȡ��ǰĿ¼�µ������ļ����ļ���
        File[] files = dir.listFiles();

        // ����files��ɾ����ǰĿ¼�µ������ļ�
        // ������ļ�����ɾ���ļ���
        // �����Ŀ¼���ݹ����removeDir��ɾ��Ŀ¼������ļ�
        for(int x = 0;x<files.length;x++){
            if(files[x].isDirectory()){
                removeDir(files[x]);
            }else{
                String name = files[x].toString();
                System.out.println(name+"::file delete result �� "+files[x].delete());
            }
        }

        // ���������forѭ������ɾ�����˵�ǰĿ¼�µ������ļ���
        // ����������ɾ����ǰĿ¼��
        System.out.println(dir + "::directory delete result �� " + dir.delete());
    }

}