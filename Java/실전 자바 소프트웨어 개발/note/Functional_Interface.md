# ✏️함수형 인터페이스 (Functional Interface)
## 📌정의
함수형 인터페이스란 추상 메서드가 단 하나만 존재하는 인터페이스를 의미한다.<br>
자바에서는 `@FunctionalInterface` 어노테이션을 사용해 함수형 인터페이스임을 명시할 수 있다.


<br>

## ✨@FunctionalInterface
✔️`@FunctionalInterface`를 선언하면 두 개 이상의 메서드를 정의할 경우 컴파일 오류가 발생한다. <br>
✔️이를 통해 개발자의 실수를 방지하고, 함수형 인터페이스로서의 역할을 명확하게 할 수 있다.

<br>

## 🎯목적
✅ 람다식과 결합하여 코드를 더욱 간결하고 가독성 좋게 만들 수 있음.<br>
✅ Java 8부터 도입된 함수형 프로그래밍 스타일을 적극 활용할 수 있음.<br>
✅ 불필요한 익명 클래스 구현을 줄이고 가독성 & 유지보수성을 향상시킴.

<br>

## 📜표준 API
자바에서는 직접 함수형 인터페이스를 정의할 수도 있지만, 기본적으로 제공되는 표준 API를 활용하면 더욱 편리하다.<br>
함수적 인터페이스 표준 API는 `java.util.function` 패키지로 제공된다. <br>
💡 대표적으로 `Predicate`, `Function`, `Consumer`, `Supplier`, `Operator`가 포함되어 있다.

<br>

## 📚참고 자료
- 🌐[☕ 함수형 인터페이스 표준 API 총정리](https://inpa.tistory.com/entry/%E2%98%95-%ED%95%A8%EC%88%98%ED%98%95-%EC%9D%B8%ED%84%B0%ED%8E%98%EC%9D%B4%EC%8A%A4-API)
- 🌐[코드 가독성 높이는 자바 람다식과 함수형 인터페이스](https://yozm.wishket.com/magazine/detail/2023/)