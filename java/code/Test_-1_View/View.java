import java.util.List;

class View{
    public String name;
    public String id;
    public int width;
    public int height;

    public View(String name,String id,int width,int height){
        this.name = name;
        this.id = id;
        this.width = width;
        this.height = height;
    }

    public String getName(){
        return name;
    }
    // ...��������
}

class ViewGroup extends View {
    // ViewGroup���ӽڵ������View��
    //      ��ViewGroup��View�����࣬�����ӽڵ�Ҳ������ViewGroup
    public List<View> children = null;

    public String groupName;

    // ...��������

    public void addView(View view){
        this.children.add(view);
    }

    // ���ݼ̳��ж��Ƿ���ViewGroup����
    public boolean isViewGroup(View view){
        return view instanceof ViewGroup;
    }

    // ...������ز���
}


class TextView extends View{
    // text view ��һЩ����
}

class SurfaceView extends View{
    // surface view ��һЩ����
}

class TestViewGroup{
    public static void main(String[] args){
        View A = new View();

        ViewGroup B = new ViewGroup();
    }
}
