class User:
    def __init__ (self, username, email = "", password = ""):
        self.username = username
        self.email = email
        self.password = password
    
    def __str__ (self):
        return self.username

class Post:
    def __init__ (self, content, author = ""):
        self.content = content
        self.author = User(author)
        self.likes = []
        self.comments = []
    
    def add_like (self, user):
        self.likes.append(User(user))
    
    def add_comment (self, user, comment):
        comment = Comment(user, comment)
        self.comments.append(comment)
    
    def get_likes_count (self):
        return len(self.likes)
    
    def get_comments (self):
        return self.comments

class Comment:
    def __init__ (self, author, content):
        self.author = User(author)
        self.content = content

posts = []
friends = []

def create_post (content):
    posts.append(Post(content))

def add_friend (user):
    friends.append(User(user))

n = int(input())

for _ in range(n):
    t = input().split()

    if t[0] == "1":
        create_post(t[1])
    elif t[0] == "2":
        add_friend(t[1])
    elif t[0] == "3":
        for i in range(len(posts)):
            if posts[i].content == t[1]:
                for user in t[3:]:
                    posts[i].add_like(user)
                break
    elif t[0] == "4":
        for i in range(len(posts)):
            if posts[i].content == t[1]:
                posts[i].add_comment(t[3], t[2])
                break
    elif t[0] == "5":
        for i in range(len(posts)):
            if posts[i].content == t[1]:
                print(posts[i].get_likes_count(), *posts[i].likes)
                break
    elif t[0] == "6":
        for i in range(len(posts)):
            if posts[i].content == t[1]:
                comments = posts[i].get_comments()
                print(*[f"{x.author} : {x.content}" for x in comments])
                break