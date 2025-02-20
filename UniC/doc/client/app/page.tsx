"use client";
import { Typography, Flex, AutoComplete } from "antd";
import { useState } from "react";

type FunctionDoc = {
	Category: string;
	Name: string;
	Header: string;
	Body: string;
	Doc: string;
};

export default function Home() {
	const [suggestions, setSuggestions] = useState([]);
	const [functionDoc, setFunctionDoc] = useState<FunctionDoc | null>(null);

	function get_suggestion(input: string) {
		fetch(`http://127.0.0.1:1323/queryFunctions?input=${input}`, {
			method: "POST",
		})
			.then((response) => response.json())
			.then((data) => {
				setSuggestions(data);
			})
			.catch(() => setSuggestions([]));
	}

	function get_function(input: string) {
		fetch(`http://127.0.0.1:1323/getFunction?input=${input}`, {
			method: "POST",
		})
			.then((response) => response.json())
			.then((data) => {
				setFunctionDoc(data as FunctionDoc);
			});
	}

	return (
		<Flex vertical gap={"middle"}>
			<Typography.Title>UniC</Typography.Title>
			<AutoComplete
				options={suggestions?.map((suggestion) => ({
					label: suggestion,
					value: suggestion,
				}))}
				onChange={(value) => get_suggestion(value)}
				onSelect={(value) => get_function(value)}
				placeholder="Search for a function"
			/>
			{functionDoc !== null ? (
				<Flex vertical align={"start"} justify="start">
					<Typography.Paragraph strong>{functionDoc.Name}</Typography.Paragraph>
					<Typography.Paragraph>{functionDoc.Header}</Typography.Paragraph>
					<>
						{functionDoc.Doc.split("@").slice(1).map((line) => (
							<Typography.Paragraph key={line}>{line.trim().replace(/[*\/]/g, "")}</Typography.Paragraph>
						))}
					</>
				</Flex>
			) : null}
		</Flex>
	);
}
