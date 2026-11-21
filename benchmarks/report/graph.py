import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("../data/data.csv")

plt.figure(figsize=(12, 7))

plt.plot(
    df["Size"],
    df["VecMs"],
    marker="o",
    linewidth=2,
    label="Vec"
)

plt.plot(
    df["Size"],
    df["StdVectorMs"],
    marker="s",
    linewidth=2,
    label="std::vector"
)

plt.plot(
    df["Size"],
    df["LinkedListMs"],
    marker="^",
    linewidth=2,
    label="LinkedList"
)

plt.xlabel("Number of Append Operations")
plt.ylabel("Execution Time (ms)")

plt.title(
    "Append Performance Comparison"
)

plt.legend()

plt.grid(
    True,
    linestyle="--",
    alpha=0.5
)

plt.tight_layout()

plt.savefig(
    "append_runtime.png",
    dpi=300
)

plt.show()