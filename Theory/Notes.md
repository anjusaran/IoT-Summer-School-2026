Q9.
# Difference Between `git clone`, `git fetch`, and `git pull`

## 1. `git clone`

**Purpose:**
`git clone` is used to create a complete copy of a remote Git repository on a local computer. It downloads all the project files, commit history, and branches, and automatically sets up the remote repository (`origin`).

**Syntax:**

```bash
git clone https://github.com/username/repository.git
```

**When to use:**

* When working with a repository for the first time.
* When creating a local copy of a project hosted on GitHub.

---

## 2. `git fetch`

**Purpose:**
`git fetch` downloads the latest commits, branches, and updates from the remote repository without merging them into the current branch. It allows you to review incoming changes before applying them.

**Syntax:**

```bash
git fetch
```

**When to use:**

* When you want to check for updates without modifying your local files.
* Before reviewing or comparing changes from collaborators.

---

## 3. `git pull`

**Purpose:**
`git pull` updates the local branch by first fetching changes from the remote repository and then automatically merging them into the current branch.

**Syntax:**

```bash
git pull origin main
```

**When to use:**

* Before starting work to ensure your local repository is up to date.
* When you want to immediately incorporate the latest changes from the remote repository.


Q10.
A .gitignore file tells Git which files and folders should not be tracked or committed to a repository. It is commonly used to exclude compiled files, temporary files, operating-system files, and IDE-specific configuration folders that are not necessary for sharing the source code.

Example .gitignore for an Arduino Project

.gitignore

What this excludes:
*.hex- Compiled Arduino firmware files
*.elf- Compiled executable/debug files
build/- Build output directory
.vscode/- VS Code settings and extensions
.DS_Store- macOS hidden system file
Thumbs.db- Windows thumbnail cache file


