public abstract class Pet {
	private int age;
	private String sex;
	private String name;
	private double height;
	private double price;


	/*
		赋值方法
	*/
	void setAge(int age) {
		this.age = age;
	}
	void setSex(String sex) {
		this.sex = sex;
	}
	void setName(String name) {
		this.name = name;
	}
	void setHeight(double height) {
		this.height = height;
	}
	void setPrice(double price) {
		this.price = price;
	}

	/*
		获取方法
	*/
	int getAge() {
		return this.age;	
	}
	String getSex() {
		return this.sex;
	}
	String getName() {
		return this.name;
	}
	double getHeight() {
		return this.height;
	}
	double getPrice(double price) {
		return this.price;
	}
}
