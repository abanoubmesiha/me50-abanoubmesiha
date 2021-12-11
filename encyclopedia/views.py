from django.shortcuts import render
from markdown2 import Markdown

from . import util

markdowner = Markdown()

def index(request):
    return render(request, "encyclopedia/index.html", {
        "entries": util.list_entries()
    })

def getEntry(req, title):
    entry = util.get_entry(title)
    if entry is None:
        return render(req, "encyclopedia/404.html", { "title": title })
    else:
        return render(req, "encyclopedia/view-entry.html", { "entry": markdowner.convert(entry) })

def search(req):
    q = req.GET.get('q')
    return HttpResponse(q)
