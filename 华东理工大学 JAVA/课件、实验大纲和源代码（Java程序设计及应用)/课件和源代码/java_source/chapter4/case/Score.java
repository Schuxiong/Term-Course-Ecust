public class Score {
	private String courseId=null;  //�γ̺� 
	private String studentId=null; //ѧ��
	 
	private int    score=0;//�ɼ�
	
	public Score() { 
	}

	public Score(String courseId, String studentId, String teacherId, int score) {
		//super();
		this.courseId = courseId;
		this.studentId = studentId;
		this.teacherId = teacherId;
		this.score = score;
	}

	public String getCourseId() {		return courseId;	}
	public void setCourseId(String courseId) {		this.courseId = courseId;	}

	public String getStudentId() {		return studentId;	}
	public void setStudentId(String studentId) {		this.studentId = studentId;	}

	public String getTeacherId() {		return teacherId;	}
	public void setTeacherId(String teacherId) {		this.teacherId = teacherId;	}

	public int getScore() {		return score;	}
	public void setScore(int score) {		this.score = score;	}
}

