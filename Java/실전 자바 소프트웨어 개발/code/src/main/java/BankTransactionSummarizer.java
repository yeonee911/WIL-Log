package main.java;


@FunctionalInterface
public interface BankTransactionSummarizer {
	double summarize(double accumulator, BankTransaction bankTransaction);
}
