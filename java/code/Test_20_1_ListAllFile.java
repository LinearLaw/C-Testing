
/**
 * @desc �г�ĳһ���ļ�������������ļ����ļ��У�������Ŀ¼
 * 
 * �ݹ�
 * 1���޶�����
 * 2���ݹ�����������ڴ����
 */

import java.io.*;
class ListAllFile {

    public static void main(String[] args){
        File dir = new File("./TestFolder");

        ListAllFile.showDir(dir,0);
    }

    /**
     * @desc ���ݴ����level����ӡ����Ӧ�Ĳ㼶��
     * @param level
     */
    public static String getLevel(int level){
        StringBuilder sb = new StringBuilder();
        sb.append("|--");

        for(int x=0;x<level;x++){
            sb.insert(0,"|");
        }

        return sb.toString();
    }

    /**
     * @desc ����һ��File���󣬽����е��ļ����ļ��д�ӡ����
     * @param dir
     * @param level
     */
    public static void showDir(File dir,int level)
    {
        String name = dir.getName();

        System.out.print(ListAllFile.getLevel(level)+name+"\n");

        // �ڴ�ӡ֮ǰ����level����+1
        level++;
        try{
            // ע�⣺������·���������ڣ���ôdir.listFiles����һ����ָ���쳣
            
            // listFiles���� ���ص�ǰĿ¼�µ������ļ����ļ��е����飬Ԫ��������File
            File[] files = dir.listFiles();

            for(int x=0;x<files.length;x++){

                // ���files[x]��һ��Ŀ¼����������±������Ŀ¼��
                if(files[x].isDirectory()){
                    showDir(files[x], level);
                }else{
                    // ������ļ�����ֱ�Ӵ�ӡ���ļ���
                    System.out.print(ListAllFile.getLevel(level) + files[x] + "\n");
                }
            }   
        }catch(Exception e){
            // System.out.print(e);

            /**
             * printStackTrace���ӡ���б�����Ϣ
             * e.toStringֻ���ӡ����������Ϣ
             */
            e.printStackTrace();
        }
    }


}
