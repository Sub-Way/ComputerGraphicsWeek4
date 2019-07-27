# ComputerGraphicsWeek4


## 4주차. Modern OpenGL


### 1.	주어진 Old Style의 샘플을 Modern style인 glDrawArrays() 방법과 glDrawElements()로 각각 변경하시오. (60점)

|glDrawArrays()로 그리기 ||+30|
|:------------------------|:---|:--------|
|glDrawElements() 로 그리기 |Vertex를 8개 사용한 경우| +30 |
|glDrawElements() 로 그리기 |Vertex를 36개 사용한 경우| +20 |



### 2.	원뿔을 Modern style로 구현하시오.  (30점)
-	원뿔을 Modern style로 구현하면 30점
-	원뿔을 Old style로 구현하면 20점
 
 ![image](https://user-images.githubusercontent.com/22046757/61993281-4e856180-b0a4-11e9-811e-de44ee176a60.png)

-	레포트를 잘 작성하였는가? 10점

### glDrawArrays()로 그리기
#### 주요 소스 코드
~~~
Vec3 vertices[] =
	{
		//왼쪽 옆 면
		Vec3(0.0, 0.0, 0.0),
		Vec3(0.0, 0.0, 1.0),
		Vec3(0.0, 1.0, 1.0),
		Vec3(0.0, 1.0, 1.0),
		Vec3(0.0, 1.0, 0.0),
		Vec3(0.0, 0.0, 0.0),

		//바닥면
		Vec3(1.0, 0.0, 1.0),
		Vec3(0.0, 0.0, 1.0),
		Vec3(0.0, 0.0, 0.0),
		Vec3(0.0, 0.0, 0.0),
		Vec3(1.0, 0.0, 0.0),
		Vec3(1.0, 0.0, 1.0),

		//오른쪽 옆 면
		Vec3(1.0, 0.0, 1.0),
		Vec3(1.0, 0.0, 0.0),
		Vec3(1.0, 1.0, 0.0),
		Vec3(1.0, 1.0, 0.0),
		Vec3(1.0, 1.0, 1.0),
		Vec3(1.0, 0.0, 1.0),

		//앞 면
		Vec3(0.0, 0.0, 1.0),
		Vec3(1.0, 0.0, 1.0),
		Vec3(1.0, 1.0, 1.0),
		Vec3(1.0, 1.0, 1.0),
		Vec3(0.0, 1.0, 1.0),
		Vec3(0.0, 0.0, 1.0),

		//윗면
		Vec3(0.0, 1.0, 1.0),
		Vec3(1.0, 1.0, 1.0),
		Vec3(1.0, 1.0, 0.0),
		Vec3(1.0, 1.0, 0.0),
		Vec3(0.0, 1.0, 0.0),
		Vec3(0.0, 1.0, 1.0),

		//뒷면
		Vec3(1.0, 0.0, 0.0),
		Vec3(0.0, 0.0, 0.0),
		Vec3(0.0, 1.0, 0.0),
		Vec3(0.0, 1.0, 0.0),
		Vec3(1.0, 1.0, 0.0),
		Vec3(1.0, 0.0, 0.0),

		//좌표축
		Vec3(0.0, 0.0, 0.0),
		Vec3(5.0, 0.0, 0.0),
		Vec3(0.0, 0.0, 0.0),
		Vec3(0.0, 5.0, 0.0),
		Vec3(0.0, 0.0, 0.0),
		Vec3(0.0, 0.0, 5.0),
	};

Vec3 colors[] =
	{
	   Vec3(0.0, 1.0, 1.0),
	   Vec3(0.0, 1.0, 1.0),
	   Vec3(0.0, 1.0, 1.0),
	   Vec3(0.0, 1.0, 1.0),
	   Vec3(0.0, 1.0, 1.0),
	   Vec3(0.0, 1.0, 1.0),

	   Vec3(1.0, 0.0, 1.0),
	   Vec3(1.0, 0.0, 1.0),
	   Vec3(1.0, 0.0, 1.0),
	   Vec3(1.0, 0.0, 1.0),
	   Vec3(1.0, 0.0, 1.0),
	   Vec3(1.0, 0.0, 1.0),

	   Vec3(1.0, 0.0, 0.0),
	   Vec3(1.0, 0.0, 0.0),
	   Vec3(1.0, 0.0, 0.0),
	   Vec3(1.0, 0.0, 0.0),
	   Vec3(1.0, 0.0, 0.0),
	   Vec3(1.0, 0.0, 0.0),

	   Vec3(0.0, 0.0, 1.0),
	   Vec3(0.0, 0.0, 1.0),
	   Vec3(0.0, 0.0, 1.0),
	   Vec3(0.0, 0.0, 1.0),
	   Vec3(0.0, 0.0, 1.0),
	   Vec3(0.0, 0.0, 1.0),

	   Vec3(0.0, 1.0, 0.0),
	   Vec3(0.0, 1.0, 0.0),
	   Vec3(0.0, 1.0, 0.0),
	   Vec3(0.0, 1.0, 0.0),
	   Vec3(0.0, 1.0, 0.0),
	   Vec3(0.0, 1.0, 0.0),
	};

	Vec3 lines[] =
	{
	   Vec3(0.0, 0.0, 0.0),
	   Vec3(5.0, 0.0, 0.0),

	   Vec3(0.0, 0.0, 0.0),
	   Vec3(0.0, 5.0, 0.0),

	   Vec3(0.0, 0.0, 0.0),
	   Vec3(0.0, 0.0, 5.0),
	};

Vec3 lines_color[] =
	{
	   Vec3(1.0, 0.0, 0.0),
	   Vec3(1.0, 0.0, 0.0),
	   Vec3(0.0, 1.0, 0.0),
	   Vec3(0.0, 1.0, 0.0),
	   Vec3(0.0, 0.0, 1.0),
	   Vec3(0.0, 0.0, 1.0),
	};

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//정육면체
		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);

		glColorPointer(3, GL_FLOAT, 0, colors[0].v_);
		glVertexPointer(3, GL_FLOAT, 0, vertices);

		glDrawArrays(GL_TRIANGLES, 0, 36);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);

		glEnd();

		//좌표축
		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);

		glColorPointer(3, GL_FLOAT, 0, lines_color[0].v_);
		glVertexPointer(3, GL_FLOAT, 0, lines);

		glDrawArrays(GL_LINES, 0, 6);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);

		glEnd();
~~~

vertices클래스에 정육면체의 면에 대한 36개의 값들을 저장했다. 그리고 그에 맞게 각 면에 해당하는 단색을 주기 위해서 colors 클래스에도 36개의 값들을 저장했다. 마찬가지로 축과 축에 대한 색을 주기 위해 각각 lines와 lines_color에 6개의 값들을 저장했다. While문 안에서 glDrawArrays를 이용하여 GL_TRIANGLES 과 LINES 로 정육면체와 좌표축을 구현하였다.

### 결과화면
 
![image](https://user-images.githubusercontent.com/22046757/61995801-15f77f00-b0c8-11e9-8d05-d74554352398.png)
 
### glDrawElements() 로 그리기
#### 주요 소스 코드

~~~
Vec3 colors[] =
	{
	   Vec3(0.0, 1.0, 1.0),
	   Vec3(1.0, 0.0, 1.0),
	   Vec3(1.0, 0.0, 0.0),
	   Vec3(0.0, 0.0, 1.0),
	   Vec3(0.0, 1.0, 0.0),
	   Vec3(1.0, 1.0, 0.0),

	};

	Vec3 vertices[] =
	{
	   Vec3(0.0, 0.0, 0.0),
	   Vec3(0.0, 0.0, 1.0),
	   Vec3(0.0, 1.0, 1.0),
	   Vec3(0.0, 1.0, 0.0),
	   Vec3(1.0, 0.0, 1.0),
	   Vec3(1.0, 0.0, 0.0),
	   Vec3(1.0, 1.0, 0.0),
	   Vec3(1.0, 1.0, 1.0)
	};

	GLbyte indices[] =
	{
	   0,2,1,  0,3,2,
	   2,3,7,  3,7,6,
	   0,3,5,  3,5,6,
	   4,7,5,   7,5,6,
	   2,1,4,   2,4,7,
	   0,1,4,   0,4,5,
	}; //정육면체의 각 면의 조합
	GLuint vbo[6];
	glGenBuffers(3, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 24, colors, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 24, vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLbyte) * 36, indices, GL_STATIC_DRAW);

glClear(GL_COLOR_BUFFER_BIT);

		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);

		//정육면체
		glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
		glColorPointer(3, GL_FLOAT, 0, 0);

		glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
		glVertexPointer(3, GL_FLOAT, 0, 0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[2]);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, 0);

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
~~~

![image](https://user-images.githubusercontent.com/22046757/61995831-522adf80-b0c8-11e9-8b9a-79c977213a37.png)

그림을 참조하여 Vertex를 8개를 사용하여 정육면체의 면을 만들 삼각형의 조합을 indices 배열안에 선언했다. 그리고 glBindBuffer와 glBufferData로 데이터를 담고 glDrawElements를 이용하여, 정육면체를 만들었다.
 
### 결과화면
![image](https://user-images.githubusercontent.com/22046757/61995836-5b1bb100-b0c8-11e9-8999-cc5d371a6bfe.png) 

 
### 원뿔 Modern style
#### 주요 소스 코드
~~~
Vec3 colors[] =
	{
	   Vec3(1.0, 0.0, 0.0),
	   Vec3(1.0, 0.0, 0.0),
	   Vec3(1.0, 0.0, 0.0),
	};

	Vec3 vertices[] =
	{
	   Vec3(1.0, 0.0, 1.0),
	   Vec3(1.0, 2.0, 1.0),
	   Vec3(1.5, 0.0, 1.5),
	};

	Vec3 lines_color[] =
	{
	   Vec3(0.0, 1.0, 0.0),
	   Vec3(0.0, 1.0, 0.0),
	   Vec3(0.0, 0.0, 1.0),
	   Vec3(0.0, 0.0, 1.0),
	   Vec3(1.0, 0.0, 0.0),
	   Vec3(1.0, 0.0, 0.0),
	};

	Vec3 lines[] =
	{
	   Vec3(0.0, 0.0, 0.0),
	   Vec3(5.0, 0.0, 0.0),

	   Vec3(0.0, 0.0, 0.0),
	   Vec3(0.0, 5.0, 0.0),

	   Vec3(0.0, 0.0, 0.0),
	   Vec3(0.0, 0.0, 5.0),
	};

const int triangle_num = 20000;
		float dtheta = 3.141592 / triangle_num;
		float r = 0.5;
		float theta = 0;

		for (int i = 0; i <= triangle_num; i++, theta += dtheta * 2) {

			glColorPointer(3, GL_FLOAT, 0, colors[0].v_);
			glVertexPointer(3, GL_FLOAT, 0, vertices);

			vertices[2].x_ = r * sin(theta) + vertices->x_;
			vertices[2].z_ = r * cos(theta) + vertices->z_;

			glDrawArrays(GL_TRIANGLE_FAN, 0, 3);
		}
~~~
vertices클래스 안에 3개의 좌표 값을 정의했다. 고정점 2개(Vec3(1.0, 0.0, 1.0), Vec3(1.0, 2.0, 1.0))와 움직이는점 1개(Vec3(1.5, 0.0, 5.0))를 선언했다. 그래서 for문 안에서 움직일점의 좌표 값을 변경하도록 식을 세웠다. vertices[2].x_ = r * sin(theta) + vertices->x_; 와 vertices[2].z_ = r * cos(theta) + vertices->z_;부분이다. 그래서 고정점을 중심으로 하고 움직이는점은 for문을 돌면 좌표 값이 변경되고, glDrawArrays를 통해 GL_TRIANGLE_FAN을 이용해 아래와 같은 원뿔을 생성한다.
#### 결과화면
![image](https://user-images.githubusercontent.com/22046757/61995842-7090db00-b0c8-11e9-9d61-a6ceb4c3cccf.png) 
