# 🎯Question

🤔```final List<BankTransaction> bankTransactions = new ArrayList<>();``` 코드는 
`ArrayList` 를 생성하려는 것 같은데 어떻게 앞에 `List` 가 오는 거지?<br>
<br>
✅`업캐스팅(Upcasting)` 때문이다.
- `업캐스팅`은 참조형 캐스팅의 일부로 상속 관계에 있는 부모와 자식 클래스 간의 형변환이다.
- `업캐스팅`은 자식 클래스가 부모 클래스 타입으로 캐스팅되는 것이다.
- `ArrayList`가 `List`를 부모 클래스로서 상속 받기 때문이다.
- `ArrayList`는 `List` 인터페이스를 `구현(implements)` 한 클래스이다

<br>업캐스팅에 관한 글 : [JAVA 업캐스팅 & 다운캐스팅 - 완벽 이해하기](https://inpa.tistory.com/entry/JAVA-%E2%98%95-%EC%97%85%EC%BA%90%EC%8A%A4%ED%8C%85-%EB%8B%A4%EC%9A%B4%EC%BA%90%EC%8A%A4%ED%8C%85-%ED%95%9C%EB%B0%A9-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0#%EC%97%85%EC%BA%90%EC%8A%A4%ED%8C%85upcasting)

<br>