
public class TeacherCourse {
	private String TeacherId=null;  //��ʦ����
	private String CourseId=null;  //�γ̺�

	public TeacherCourse() {
		// TODO Auto-generated constructor stub
	}

	public TeacherCourse(String teacherId, String courseId) {
		super();
		TeacherId = teacherId;
		CourseId = courseId;
	}

	public String getTeacherId() {
		return TeacherId;
	}

	public void setTeacherId(String teacherId) {
		TeacherId = teacherId;
	}

	public String getCourseId() {
		return CourseId;
	}

	public void setCourseId(String courseId) {
		CourseId = courseId;
	} 
  
}
