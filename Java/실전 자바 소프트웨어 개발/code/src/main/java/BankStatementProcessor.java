package main.java;

import java.time.Month;
import java.util.ArrayList;
import java.util.List;

public class BankStatementProcessor {

	private final List<BankTransaction> bankTransactions;
	public BankStatementProcessor(final List<BankTransaction> bankTransactions) {
		this.bankTransactions = bankTransactions;
	}

	public double summarizeTransactions(final BankTransactionSummarizer bankTransactionSummarizer) {
		double result = 0;
		for (final BankTransaction bankTransaction : bankTransactions) {
			result = bankTransactionSummarizer.summarize(result, bankTransaction);
		}
		return result;
	}

	public double calculateTotalInMonth(final Month month) {
		return summarizeTransactions((acc, bankTransaction)
			-> bankTransaction.getDate().getMonth() == month ? acc + bankTransaction.getAmount() : acc);
	}

	public List<BankTransaction> findTransactions(final BankTransactionFilter bankTransactionFilter) {
		final List<BankTransaction> result = new ArrayList<>();
		for (final BankTransaction bankTransaction : bankTransactions) {
			if (bankTransactionFilter.test(bankTransaction)) {
				result.add(bankTransaction);
			}
		}
		return result;
	}

	public List<BankTransaction> findTransactionGreaterThanEqual(final int amount) {
		return findTransactions(bankTransaction -> bankTransaction.getAmount() >= amount); // test 메서드를 구현
	}
}
