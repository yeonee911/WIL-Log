package test.java;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import main.java.BankStatementCSVParser;
import main.java.BankStatementParser;

public class BankStatementCSVParserTest {
	private final BankStatementParser statementParser = new BankStatementCSVParser();

	@Test	// 해당 메서드가 유닛테스트의 실행 대상임을 알린다
	public void shouldParseOneCorrectLine() throws Exception {
		Assertions.fail("Not yet implemented");
	}

}