import sys
import time
import Tkinter as tk

def shift(l):
    return (l[1:] + l[:1]) 

def draw_node( canvas, x, y, color="#c3c3c3" , pos=0):
    if pos == -1:
        print "start"
        border = "#00ff00"
    elif pos == 1:
        print "end"
        border = "#ff0000"
    else:
        border = "#eeeeee"
    canvas.create_rectangle(x, y, x + 10, y + 10, outline=border, fill=color)
    
def draw_line( canvas, n1, n2 ):
    canvas.create_line(n1['x'], n1['y'], n2['x'], n2['y'] )

def get_ants():
    line = sys.stdin.readline()  
    try:
        nb = int(line)
    except ValueError:
        print "error"
        sys.exit()
    return nb

def update_max( lemin , x, y ):
    if ( x > lemin['maxx'] ):
        lemin['maxx'] = x
    if ( y > lemin['maxy'] ):
        lemin['maxy'] = y

def parser( lemin, nodes ):
    pos = 0
    for line in sys.stdin:
        if len ( line ) == 1:
            return
        if line[-1] == "\n":
            line = line[:-1]
        print( line )
        if line == "##start":
            pos = -1
            continue
        elif line == "##end":
            pos = 1
            continue
        elif line.startswith( '#' ):
            continue
        if '-' not in line:
            n, x, y = line.split()
            nodes[n] = {'name': n, 'links': []}
            nodes[n]['x'] = int(x) * 10
            nodes[n]['y'] = int(y) * 10
            update_max( lemin , nodes[n]['x'], nodes[n]['y'])
            nodes[n]['pos'] = pos
            pos = 0
        else:
            n1, n2 = line.split('-')
            nodes[n1]['links'].append( n2 )
            nodes[n2]['links'].append( n1 )

def print_map( canvas, lemin ):
    tab = lemin['nodes'].values()
    for node in tab:
        print node
        draw_node( canvas, node['x'], node['y'] , "#c3c3c3", node['pos'])
        for link in node['links']:
            draw_line( canvas, node, lemin['nodes'][link] ) 
    canvas.pack()

def reset_canvas( canvas, lemin ):
    nodes = lemin['nodes'].values()
    for node in nodes:
        draw_node( canvas, node['x'], node['y'], "#c3c3c3" , node['pos'] )

def store_ants( lemin ):
    lemin['ants'] = []
    for line in sys.stdin:
        lemin['ants'].append( line )

def put_ants( canvas, lemin ):
    if len(lemin['ants']) > 0:
        line = lemin['ants'][0]
        lemin['ants'] = lemin['ants'][1:]
    else:
        sys.exit()
    reset_canvas( canvas, lemin )
    ants = line.split(' ')
    for ant in ants:
        a, r = ant[1:].split('-')
        if r[-1] == "\n":
            r = r[:-1]
        print a + "  " + r
        r = lemin['nodes'][r]
        c = lemin['colors'][int(a) % 8]
        draw_node( canvas, r['x'], r['y'], c , r['pos'])
    #canvas.pack()
    canvas.after( 2000, put_ants, canvas, lemin )

def main ():
    #creating the window
    app = tk.Tk()
    app.title( "test" )

    #storing the data from ./lem-in output
    lemin = {'nodes': {}, 'maxx': 0, 'maxy': 0}
    lemin['colors'] = ["#d87373", "#eca162", "#33a99a", "#6648a1", "#db3882", "#ff3a3a", "#f2974a", "#6f0808"]
    lemin['nb_ants'] = get_ants()
    parser( lemin, lemin['nodes'] )
    store_ants( lemin )
    print lemin
    canvas = tk.Canvas( app, height=lemin['maxx'] + 10, width=lemin['maxy'] + 10 )
    print_map( canvas, lemin )
    put_ants( canvas, lemin )
    app.mainloop()

main()
