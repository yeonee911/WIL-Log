# 🎯Question

## 1️⃣ 업캐스팅(Upcasting)
🤔```final List<BankTransaction> bankTransactions = new ArrayList<>();``` 코드는
`ArrayList` 를 생성하려는 것 같은데 어떻게 앞에 `List` 가 오는 거지?<br>

✅`업캐스팅(Upcasting)` 때문이다.
- `업캐스팅`은 참조형 캐스팅의 일부로 상속 관계에 있는 부모와 자식 클래스 간의 형변환이다.
- `업캐스팅`은 자식 클래스가 부모 클래스 타입으로 캐스팅되는 것이다.
- `ArrayList`가 `List`를 부모 클래스로서 상속 받기 때문이다.
- `ArrayList`는 `List` 인터페이스를 `구현(implements)` 한 클래스이다

<br>

🤔```final BankStatementParser bankStatementParser = new BankStatementCSVParser();```에서 
좌측`BankStatementParser`과 우측`BankStatementCSVParser`의 타입이 다른데도 
코드가 동작하는 이유는?<br>

✅`업캐스팅(Upcasting)` 때문이다.
- `BankStatementParser`는 인터페이스(또는 부모 클래스)
- `BankStatementCSVParser`는 인터페이스를 구현한 클래스(또는 자식 클래스)

<br>🌐업캐스팅에 관한 글 : [JAVA 업캐스팅 & 다운캐스팅 - 완벽 이해하기](https://inpa.tistory.com/entry/JAVA-%E2%98%95-%EC%97%85%EC%BA%90%EC%8A%A4%ED%8C%85-%EB%8B%A4%EC%9A%B4%EC%BA%90%EC%8A%A4%ED%8C%85-%ED%95%9C%EB%B0%A9-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0#%EC%97%85%EC%BA%90%EC%8A%A4%ED%8C%85upcasting)

<br>

## 2️⃣ String[] vs String...
🤔```public static void main(String[] args) throws IOException```과
```public static void main(final String... args) throws IOException```
의 차이가 뭐지?<br>

✅ **매개 변수의 선언 방식**의 차이이다. `String... args`는 `가변 인자`를 사용했다.

### 📌`String[] args` : 일반 배열
- `args`는 `String`타입의 **배열**
- 실행 시 전달된 인자들이 배열로 들어감

### 📌`String... args` : 가변 인자
- `args`는 **가변 인자**로 선언됨
- 더 유연하게 여러 개의 인자를 받을 수 있다

|     선언 방식     |내부 동작|          특징           |
|:-------------:|:---:|:---------------------:|
| String[] args | 배열  |     일반적인 방식, 명확함      | 
|String... args|배열처럼 동작| 가변 인자로 다른 메서드에도 사용 가능 |

### ✨가변 인수(Variable Arguments)
- 정의 : 매개변수로 들어오는 값의 개수와 상관없이 동적으로 인수를 받아 기능
- 사용 방법 : `타입... 매개변수명`
- 작동 방식 : 컴파일 시 파라미터로 넘겨지는 값들을 배열로 처리

<br>🌐참고할 만한 글 : [☕ 가변 인수Varargs 매개변수를 동적으로](https://inpa.tistory.com/entry/JAVA-%E2%98%95-%EA%B0%80%EB%B3%80-%EC%9D%B8%EC%88%98Varargs-%EB%A7%A4%EA%B0%9C%EB%B3%80%EC%88%98%EB%A5%BC-%EB%8F%99%EC%A0%81%EC%9C%BC%EB%A1%9C)

<br>

## 3️⃣인터페이스 : implements와 매개변수 차이
🤔```public double summarizeTransactions(final BankTransactionSummarizer bankTransactionSummarizer)```
여기서 매개변수의 `BankTransactionSummarizer`가 인터페이스인데 인터페이스가 매개변수로 들어가는게 가능한가? 
인터페이스는 `implements`로 구현하는거 아닌가?

✅ `업캐스팅(Upcasting)`과 `다형성(Polymorphism)` 개념이 적용된 것이다.<br>
그런데 인터페이스는 직접 객체를 생성할 수 없으니까, 실제로는 `구현체(클래스)`가 전달된다. 
즉, 이 메서드를 호출할 때는 인터페이스를 구현한 `클래스의 객체`를 전달한다.

### ✔️ implements와 매개변수로 인터페이스 받는 것의 차이
|    구분	     |  설명  |
|:----------:|:----:|
|`implements`	| 클래스가 인터페이스를 구현할 때 사용 (`class A implements B`) |
|인터페이스 매개변수	 |메서드에서 인터페이스를 받아 다형성을 활용|

즉, `implements`는 클래스에서 인터페이스를 **구현**하는 것이고, 
매개변수로 인터페이스를 받으면 **구현체를 다양하게 활용**할 수 있는 것!
