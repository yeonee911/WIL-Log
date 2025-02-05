package test.java;

import java.time.LocalDate;
import java.time.Month;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import main.java.BankStatementCSVParser;
import main.java.BankStatementParser;
import main.java.BankTransaction;

public class BankStatementCSVParserTest {
	private final BankStatementParser statementParser = new BankStatementCSVParser();

	@Test	// 해당 메서드가 유닛테스트의 실행 대상임을 알린다
	public void shouldParseOneCorrectLine() throws Exception {
		final String line = "30-01-2017,-50,Tesco";

		final BankTransaction result = statementParser.parseFrom(line);

		final BankTransaction expected
			= new BankTransaction(LocalDate.of(2017, Month.JANUARY, 30), -50, "Tesco");
		final double tolerance = 0.0d;

		Assertions.assertEquals(expected.getDate(), result.getDate());;
		Assertions.assertEquals(expected.getAmount(), result.getAmount(), tolerance);
		Assertions.assertEquals(expected.getDescription(), result.getDescription());
	}

}
