public class Teacher {
	private String Id=null;  //����
	private String name=null;  //����
	private String department=null; //ϵ��    

	public Teacher() {	
		//super();
	}
	public Teacher(String id, String name, String department) {
		//super();
		Id = id;
		this.name = name;
		this.department = department;
	}

	public String getId() {		return Id;	}
	public void setId(String id) {		Id = id;	}

	public String getName() {		return name;	}
	public void setName(String name) {		this.name = name;	}

	public String getDepartment() {		return department;	}
	public void setDepartment(String department) {		this.department = department;	}
  
}
