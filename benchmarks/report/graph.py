import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("../data/data.csv")

capacity_df = pd.read_csv(
    "../data/capacity_growth.csv"
)

std_capacity_df = pd.read_csv(
    "../data/std_capacity_growth.csv"
)

plt.rcParams.update({
    "font.size": 11
})

# ==================================================
# 1.
# Vec vs std::vector vs LinkedList
# Small Inputs (0 - 5000)
# ==================================================

small = df[df["Size"] <= 5000]

plt.figure(figsize=(12, 7))

plt.plot(
    small["Size"],
    small["VecMs"],
    marker="o",
    linewidth=2,
    label="Vec"
)

plt.plot(
    small["Size"],
    small["StdVectorMs"],
    marker="s",
    linewidth=2,
    label="std::vector"
)

plt.plot(
    small["Size"],
    small["LinkedListMs"],
    marker="^",
    linewidth=2,
    label="LinkedList"
)

plt.title(
    "Append Performance (0 - 5,000 Appends)"
)

plt.xlabel("Number of Append Operations")
plt.ylabel("Execution Time (ms)")

plt.grid(
    True,
    linestyle="--",
    alpha=0.5
)

plt.legend()

plt.tight_layout()

plt.savefig(
    "append_small_all.png",
    dpi=300
)

# ==================================================
# 2.
# Vec vs std::vector
# Very Small Inputs (0 - 1000)
# ==================================================

very_small = df[df["Size"] <= 1000]

plt.figure(figsize=(12, 7))

plt.plot(
    very_small["Size"],
    very_small["VecMs"],
    marker="o",
    linewidth=2,
    label="Vec"
)

plt.plot(
    very_small["Size"],
    very_small["StdVectorMs"],
    marker="s",
    linewidth=2,
    label="std::vector"
)

plt.title(
    "Vec vs std::vector (0 - 1,000 Appends)"
)

plt.xlabel("Number of Append Operations")
plt.ylabel("Execution Time (ms)")

plt.grid(
    True,
    linestyle="--",
    alpha=0.5
)

plt.legend()

plt.tight_layout()

plt.savefig(
    "append_vectors_small.png",
    dpi=300
)

# ==================================================
# 3.
# Vec vs std::vector vs LinkedList
# Large Inputs (5,000 - 1,000,000)
# ==================================================

large = df[df["Size"] >= 5000]

plt.figure(figsize=(12, 7))

plt.plot(
    large["Size"],
    large["VecMs"],
    marker="o",
    linewidth=2,
    label="Vec"
)

plt.plot(
    large["Size"],
    large["StdVectorMs"],
    marker="s",
    linewidth=2,
    label="std::vector"
)

plt.plot(
    large["Size"],
    large["LinkedListMs"],
    marker="^",
    linewidth=2,
    label="LinkedList"
)

plt.title(
    "Append Performance (5,000 - 1,000,000 Appends)"
)

plt.xlabel("Number of Append Operations")
plt.ylabel("Execution Time (ms)")

plt.grid(
    True,
    linestyle="--",
    alpha=0.5
)

plt.legend()

plt.tight_layout()

plt.savefig(
    "append_large_all.png",
    dpi=300
)

# ==================================================
# 4.
# Capacity Growth
# Initial Growth (0 - 16)
# ==================================================

vec_small_cap = capacity_df[
    capacity_df["Size"] <= 16
]

std_small_cap = std_capacity_df[
    std_capacity_df["Size"] <= 16
]

plt.figure(figsize=(12, 7))

plt.step(
    vec_small_cap["Size"],
    vec_small_cap["Capacity"],
    where="post",
    linewidth=3,
    linestyle="--",
    marker="o",
    label="Vec"
)

plt.step(
    std_small_cap["Size"],
    std_small_cap["Capacity"],
    where="post",
    linewidth=2,
    marker="s",
    label="std::vector"
)

plt.title(
    "Initial Capacity Growth (0 - 16 Elements)"
)

plt.xlabel("Elements Stored")
plt.ylabel("Capacity")

plt.grid(
    True,
    linestyle="--",
    alpha=0.5
)

plt.legend()

plt.tight_layout()

plt.savefig(
    "capacity_small.png",
    dpi=300
)

# ==================================================
# 5.
# Capacity Growth
# 16 - 524,289
# ==================================================

vec_large_cap = capacity_df[
    capacity_df["Size"] >= 16
]

std_large_cap = std_capacity_df[
    std_capacity_df["Size"] >= 16
]

plt.figure(figsize=(12, 7))

plt.step(
    vec_large_cap["Size"],
    vec_large_cap["Capacity"],
    where="post",
    linewidth=3,
    linestyle="--",
    label="Vec"
)

plt.step(
    std_large_cap["Size"],
    std_large_cap["Capacity"],
    where="post",
    linewidth=2,
    label="std::vector"
)

plt.title(
    "Capacity Growth (16 - 524,289 Elements)"
)

plt.xlabel("Elements Stored")
plt.ylabel("Capacity")

plt.grid(
    True,
    linestyle="--",
    alpha=0.5
)

plt.legend()

plt.tight_layout()

plt.savefig(
    "capacity_large.png",
    dpi=300
)

print("Graphs generated successfully.")

plt.show()