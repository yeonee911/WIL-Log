# 🎯Question

## 1️⃣ 단위
🤔크기를 나타내느 속성값에는 수치, `match_parent` 그리고 `wrap_content`가 있다.
이때 수치의 단위로 `px`과 `dp`이 있는데 이 둘의 차이점은 뭐지?

✅`dp`는 화면 밀도에 따라 크기가 조정되지만, `px`는 고정된 크기의 실제 픽셀 단위이다<br>
### ✨px
✔️실제 화면에 표시되는 물리적인 픽셀 단위<br>
✔️기기 해상도에 따라 픽셀 밀도가 다를 수 있음<br>
✔️같은 px 값을 사용해도 화면 크기와 해상도에 따라 크기가 달라 보일 수 있음<br>

### ✨dp
✔️화면 밀도(DPI, dots per inch)에 영향을 받지 않는 단위<br>
✔️다양한 해상도의 기기에서 동일한 크기를 유지하도록 설계됨<br>
✔️1dp = 1px (기본 밀도 mdpi, 160dpi 기준)<br>
✔️고밀도 화면에서는 dp가 더 많은 px로 변환됨<br>

### ⚡dp단위를 픽셀 단위로 변환
```px = dp * (dpi / 160)``` <br>

💡픽셀을 계산하기 위해 이 수식을 하드코딩하지 마세요. 대신 `TypedValue.applyDimension()`, 
이 함수는 다양한 유형의 크기 (dp, sp 등)를 픽셀로 변환합니다.

<br>

📚참고 자료
- 🌐[Android Developers 공식 문서: 다양한 픽셀 밀도 지원](https://developer.android.com/training/multiscreen/screendensities?hl=ko)