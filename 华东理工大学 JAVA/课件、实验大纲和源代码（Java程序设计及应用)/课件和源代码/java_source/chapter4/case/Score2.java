
public class Score {   
	private Student student=null;  //ѧ��
	private Teacher teacher=null;  //��ʦ
	private Course course=null;    //�γ�
	private int score=0;  //�ɼ�
	
	public Score() {		
	}

	public Score(Student student, Teacher teacher, Course course, int score) {
		//super();
		this.student = student;
		this.teacher = teacher;
		this.course = course;
		this.score = score;
	}

	public Student getStudent() {		return student;	}
	public void setStudent(Student student) {		this.student = student;	}

	public Teacher getTeacher() {		return teacher;	}
	public void setTeacher(Teacher teacher) {		this.teacher = teacher;	}

	public Course getCourse() {		return course;	}
	public void setCourse(Course course) {		this.course = course;	}

	public int getScore() {		return score;	}

	public void setScore(int score) {		this.score = score;	} 
}
