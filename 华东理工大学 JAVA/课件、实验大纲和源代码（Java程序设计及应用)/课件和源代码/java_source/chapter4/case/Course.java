
public class Course {
	private String Id=null;  //�γ̺�
	private String name=null;  //�γ���
	private String department=null; //ϵ��
    private String classname=null; //�༶
    
	public Course() { 
	}

	public Course(String id, String name, String department, String classname) {
		//super();
		Id = id;
		this.name = name;
		this.department = department;
		this.classname = classname;
	}

	public String getId() {		return Id;	}
	public void setId(String id) {		Id = id;	}

	public String getName() {		return name;	}
	public void setName(String name) {		this.name = name;	}

	public String getDepartment() {		return department;	}
	public void setDepartment(String department) {		this.department = department;	}

	public String getClassname() {		return classname;	}
	public void setClassname(String classname) {		this.classname = classname;	}

}

